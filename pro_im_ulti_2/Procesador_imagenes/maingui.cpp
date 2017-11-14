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
    selector_gray_.setModal(false);

    connect(&selector_gray_, SIGNAL(image_selected(int)), this, SLOT(gray_Convert(int)));
    connect(&selector_ecu_, SIGNAL(image_selected(int)), this, SLOT(ecua_histogram(int)));
    connect(&selector_gamma_, SIGNAL(image_selected(QVector<double>)), this, SLOT(gamma_correction(QVector<double>)));
    connect(&b_and_c_, SIGNAL(image_selected(QVector<int>)), this, SLOT(brightness_Contrast(QVector<int>)));
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

    QAction *brilloContraste = ui_->menuEditar->addAction(tr("&Brillo y contraste"), this, &MainGui::brightnessContrast);
    brilloContraste->setStatusTip(tr("Modificar el brillo y el contraste de la imagen"));

    QAction *Ecualizar = ui_->menuEditar->addAction(tr("&Ecualizar"), this, &MainGui::ecu);
    Ecualizar->setStatusTip(tr("Ecualización del histograma"));

    QAction *Gamma = ui_->menuEditar->addAction(tr("&Gamma"), this, &MainGui::gamma);
    Ecualizar->setStatusTip(tr("Correción Gamma"));


    //Menu Imagen
    QAction *ShowInformation = ui_->menuImagen->addAction(tr("&Información"), this, &MainGui::showInfo);
    ShowInformation->setStatusTip(tr("Muestra la información de la imagen"));

     ui_->menuImagen->addSeparator();

    QAction *ConvertGray = ui_->menuImagen->addAction(tr("&Convertir a escala de grises"), this, &MainGui::grayConvert);
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
        connect(viewer, SIGNAL(info_updated(QVector<QString>)), &information_, SLOT(info_updated(QVector<QString>)));

        if(viewer->openImage(fileName)){
            information_.add_selection(fileName);
            histogram_.add_selection(fileName);
            selector_gray_.add_selection(fileName);
            selector_gamma_.add_selection(fileName);
            b_and_c_.add_selection(fileName);
            selector_ecu_.add_selection(fileName);
            histogram_.add_histogram(viewer->histogram_data());
            histogram_.add_gray(viewer->gray_data());
            statusBar()->showMessage(tr("Imagen abierta correctamente."));
            viewers_.push_back(viewer);
            viewers_[counter_]->show();
            counter_++;
            qDebug() << counter_;
            viewer->update_info();
            connect(viewer, SIGNAL(histogram_updated(QVector<QVector<int> >)), &histogram_, SLOT(actualizar_histograma(QVector<QVector<int> >)));
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

void MainGui::brightnessContrast(){
    if(counter_ > 0){
       b_and_c_.show();
    }
    else
        statusBar()->showMessage(tr("Necesario abrir una imagen primero."));
}

void MainGui::grayConvert(){
    if(counter_ > 0){
       selector_gray_.show();
    }
    else
        statusBar()->showMessage(tr("Necesario abrir una imagen primero."));
}

void MainGui::gray_Convert(int a){
    viewers_[a]->convert_to_gray();
}

void MainGui::brightness_Contrast(QVector<int> a){
    viewers_[a[0]]->brightness_contrast(a[1], a[2]);
}

void MainGui::ecu(){
    if(counter_ > 0){
       selector_ecu_.show();
    }
    else
        statusBar()->showMessage(tr("Necesario abrir una imagen primero."));
}

void MainGui::ecua_histogram(int a){
    viewers_[a]->ecu_histogram();
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

void MainGui::gamma(){
    if(counter_ > 0){
       selector_gamma_.show();
    }
    else
        statusBar()->showMessage(tr("Necesario abrir una imagen primero."));
}

void MainGui::gamma_correction(QVector<double> data){
    viewers_[int(data[0])]->gamma_correction(data[1]);
}
