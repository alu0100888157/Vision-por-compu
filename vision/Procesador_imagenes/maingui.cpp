#include "maingui.h"
#include "ui_maingui.h"

MainGui::MainGui(QWidget *parent):  //Constructor.
QMainWindow(parent),
ui_(new Ui::MainGui),
curFile_(""),
counter_(0){
    ui_->setupUi(this);

    createActions();
    createStatusBar();

    readSettings();
    setCurrentImage(curFile_);
    information_.setModal(false);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    if(cameras.count() > 0){
         qDebug() << "Cámaras disponibles:";
        foreach (const QCameraInfo &cameraInfo, cameras)
            qDebug() << cameraInfo.deviceName() << " ";
    }
    else{
        qDebug() << "Niguna cámara disponible.";

        //QAction *Take_Pic= ui_->menuarchivo->actions()
    }
}

MainGui::~MainGui(){    //Destructor.
    delete ui_;
}

void MainGui::closeEvent(QCloseEvent *event){   //Manejo del evento de cierre de la ventana.
   if(event->isAccepted()){
    writeSettings();
    statusBar()->showMessage("Adios!");
    terminate();
   }
   else{
    statusBar()->showMessage("Algo ha salido mal...");
   }
}

void MainGui::open(){   //Apertura de un archivo.
    QString fileName = QFileDialog::getOpenFileName(this);

    if(!fileName.isEmpty())
        loadFile(fileName);
}

bool MainGui::save(){   //Guardado de un archivo modificado.
    if (curFile_.isEmpty()) {
        return saveAs();
    } else {
        return saveImage(curFile_);
    }
}

bool MainGui::saveAs(){ //Guardado de un archivo modificado con un nombre concreto.
    QFileDialog dialog(this);

    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return saveImage(dialog.selectedFiles().first());
}

void MainGui::about(){
    QMessageBox::about(this, tr("Sobre la aplicación"),
             tr("Este <b>Programa</b> ha sido desarrollada "
                "como proyecto final de la asignatura de "
                "visión por computador del cuarto año del grado."));
}

void MainGui::imageWasModified(){   //La imagen ha sido modificada.

}

void MainGui::writeSettings(){  //Escritura de las opciones.
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

void MainGui::readSettings(){   //Lectura de las opciones.
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();

    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

void MainGui::createActions(){  //Inicialización de las acciones del programa.

    //Menu Archivo
    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/Imagenes/Imagenes_GUI/open.png"));
    QAction *openAct = new QAction(openIcon, tr("&Abrir..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Abrir una imagen"));
    connect(openAct, &QAction::triggered, this, &MainGui::open);
    ui_->menuarchivo->addAction(openAct);
    ui_->toolBar->addAction(openAct);


    const QIcon picIcon = QIcon(":/Imagenes/Imagenes_GUI/takepic.png");
    QAction *takepic = new QAction(picIcon, tr("&Tomar foto..."), this);
    takepic->setStatusTip(tr("Tomar foto"));
    connect(takepic, &QAction::triggered, this, &MainGui::takePic);
    ui_->menuarchivo->addAction(takepic);
    ui_->toolBar->addAction(takepic);

    const QIcon realtimeIcon = QIcon(":/Imagenes/Imagenes_GUI/realtime.png");
    QAction *realTime = new QAction(realtimeIcon, tr("&Abrir captura de vídeo..."), this);
    realTime->setStatusTip(tr("Abrir una captura de vídeo en tiempo real"));
    connect(realTime, &QAction::triggered, this, &MainGui::real_time);
    ui_->menuarchivo->addAction(realTime);
    ui_->toolBar->addAction(realTime);

    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/Imagenes/Imagenes_GUI/save.png"));
    QAction *saveAct = new QAction(saveIcon, tr("&Guardar"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Guarda la imagen al disco"));
    connect(saveAct, &QAction::triggered, this, &MainGui::save);
    ui_->menuarchivo->addAction(saveAct);
    ui_->toolBar->addAction(saveAct);

    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as",  QIcon(":/Imagenes/Imagenes_GUI/saveAs.png"));
    QAction *saveAsAct = ui_->menuarchivo->addAction(saveAsIcon, tr("Guardar &como..."), this, &MainGui::saveAs);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Guarda la imagen bajo un nuevo nombre"));
    ui_->toolBar->addAction(saveAsAct);
    ui_->toolBar->addSeparator();
    ui_->menuarchivo->addSeparator();

    QAction *Terminate = ui_->menuarchivo->addAction(tr("Cerrar todas las ventanas"), this, &MainGui::showInfo);
    Terminate->setStatusTip(tr("Cerrar todas las ventanas abiertas"));

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = ui_->menuarchivo->addAction(exitIcon, tr("S&alir"), this, &QWidget::close);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Salir de la aplicación"));

    //Menu editar
    QAction *transLineal = ui_->menuEditar->addAction(tr("&Transformación lineal"), this, &MainGui::transLineal);
    transLineal->setStatusTip(tr("Transformaciónes lineales por tramos"));

    //Menu Imagen
    QAction *ShowInformation = ui_->menuImagen->addAction(tr("&Información"), this, &MainGui::showInfo);
    ShowInformation->setStatusTip(tr("Muestra la información de la imagen"));

     ui_->menuImagen->addSeparator();

    QAction *ConvertGray = ui_->menuImagen->addAction(tr("&Convertir a escala de grises"), this, &MainGui::showInfo);
    ConvertGray->setStatusTip(tr("Transforma una imagen a escala de grises"));

    QAction *ConvertColor = ui_->menuImagen->addAction(tr("&Convertir a RGB"), this, &MainGui::showInfo);
    ConvertColor->setStatusTip(tr("Transforma una imagen a RGB"));

    ui_->menuImagen->addSeparator();

    QAction *GenerateHistogram = ui_->menuImagen->addAction(tr("&Histograma"), this, &MainGui::showHistogram);
    GenerateHistogram->setStatusTip(tr("Genera histograma de la imagen seleccionada"));

    QAction *GenerateHistogramAc = ui_->menuImagen->addAction(tr("&Histograma Acumulado"), this, &MainGui::showHistogramAc);
    GenerateHistogramAc->setStatusTip(tr("Genera histograma acumulado de la imagen seleccionada"));


    //Menu Ayuda
    QAction *aboutAct = ui_->menuAyuda->addAction(tr("&Sobre"), this, &MainGui::about);
    aboutAct->setStatusTip(tr("Muestra la info básica sobre la app"));

    QAction *aboutQtAct = ui_->menuAyuda->addAction(tr("Sobre &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Muestra la info sobre la librería Qt"));

}

void MainGui::createStatusBar(){    //Inicialización de la barra de estado.
     statusBar()->showMessage(tr("Programa Iniciado correctamente."));
}

void MainGui::setCurrentImage(const QString &fileName){ //Fijar la imagen actual.

}

void MainGui::loadFile(const QString &fileName){
    if(counter_ != 2){
        Image_viewer *viewer = new Image_viewer(counter_, fileName);

        if(viewer->openImage(fileName)){
            information_.add_selection(fileName);
            histogram_.add_selection(fileName);
            histogram_.add_histogram(viewer->histogram_data());
            histogram_.add_gray(viewer->gray_data());
            statusBar()->showMessage(tr("Imagen abierta correctamente."));
            viewers_.push_back(viewer);
            viewers_[counter_]->show();
            counter_++;
            qDebug() << counter_;
        }
        else{
            statusBar()->showMessage(tr("Imagen NO abierta correctamente."));
        }
    }
    else{
         statusBar()->showMessage(tr("Numero máximo de imagenes simultaneas alcanzado."));
    }
}

bool MainGui::saveImage(const QString &fileName){

}

void MainGui::terminate(){
    information_.close();
    foreach (Image_viewer *viewer, viewers_) {
        viewer->close();
    }
}

void MainGui::showInfo(){
    if(counter_ > 0)
        information_.show();
    else
        statusBar()->showMessage(tr("Necesario abrir una imagen primero."));
}

void MainGui::transLineal(){

}

void MainGui::showHistogram(){
    if(counter_ > 0){
       histogram_.set_mode(true);
       histogram_.show();
    }
    else
        statusBar()->showMessage(tr("Necesario abrir una imagen primero."));
}

void MainGui::showHistogramAc(){
    if(counter_ > 0){
       histogram_.set_mode(false);
       histogram_.show();
    }
    else
        statusBar()->showMessage(tr("Necesario abrir una imagen primero."));
}

void MainGui::takePic(){
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    camara_selector dialogo(cameras);
    dialogo.exec();

    QCameraInfo cam = dialogo.init();
    QString mensaje = "Cámara " + cam.deviceName() + " en uso.";

}

void MainGui::real_time(){
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    camara_selector dialogo(cameras);
    dialogo.exec();

    QCameraInfo cam = dialogo.init();
    QString mensaje = "Cámara " + cam.deviceName() + " en uso.";
}
