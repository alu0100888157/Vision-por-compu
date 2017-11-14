#include "image_viewer.h"

Image_viewer::Image_viewer(qint8 id, QString name, QWidget *parent) :
    QWidget(parent, Qt::Window),
    id_(id){
    layout_ = new QVBoxLayout;
    label_ = new QLabel;
    status_ = new QLabel;
    gray_ = false;
    label_->setScaledContents(true);
    this->setMouseTracking(true);
    this->setWindowTitle(name);
}

void Image_viewer::mouseMoveEvent(QMouseEvent *event){
    if(label_->rect().contains(event->pos())){
        QString data("[" + QString::number(event->pos().rx()) + "," + QString::number(event->pos().ry()) + "]");
        QString dimensions = "[" + QString::number(image_.width()) + "," + QString::number(image_.height()) + "]";
        status_->setText(dimensions + " / " + data);
    }
    else{
        status_->setText("");
    }
}

QVector<QVector<int>> Image_viewer::histogram_data(void){
    QVector<QVector<int>> data;
    QVector<int> R;
    QVector<int> G;
    QVector<int> B;

    QColor dummy;
    data.resize(3);
    R.resize(256);
    G.resize(256);
    B.resize(256);
    for(int i = 0; i < image_.height(); i++){
        for(int j = 0; j < image_.width(); j++){
            dummy = image_.pixelColor(j,i);
            R[dummy.red()] = R[dummy.red()] + 1;
            G[dummy.blue()] = G[dummy.blue()] + 1;
            B[dummy.green()] = B[dummy.green()] + 1;
        }
    }

    data[0] = R;
    data[1] = G;
    data[2] = B;

    histograma_ = data;
    return data;
}

QVector<int> Image_viewer::get_brillo_y_contraste(void){
    double br = 0;
    double cr = 0;
    double bg = 0;
    double cg = 0;
    double bb = 0;
    double cb = 0;
    int brillo_gris;
    double v;
    QVector<int> resultado;
    int nt = image_.width() * image_.height();

    for(int i = 0; i <= 255; i++){
        br += i * histograma_[0][i];
        bg += i * histograma_[1][i];
        bb += i * histograma_[2][i];
    }

    br = br / nt;
    bg = bg / nt;
    bb = bb / nt;

    brillo_gris = 0.3*br + 0.59*bg + 0.11*bb;

    qDebug() << br << " " << bg << " " << bb << " " << brillo_gris;

    for(int i = 0; i <= 255; i++){
        cr += histograma_[0][i] * (i - br) * (i - br)/nt;
        cg += histograma_[1][i] * (i - bg) * (i - bg)/nt;
        cb += histograma_[2][i] * (i - bb) * (i - bb)/nt;
    }

    double v2 = 0.09 * cr + 0.3481 * cg + 0.0121 * cb;
    v = sqrt(v2);

    qDebug() << cr << " " << cg << " " << cb << v;

    resultado.append(brillo_gris);
    resultado.append(v);

    return resultado;
}

bool Image_viewer::gray_data(void){
    return gray_;
}

void Image_viewer::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}

void Image_viewer::closeEvent(QCloseEvent *event){   //Manejo del evento de cierre de la ventana.
   if(event->isAccepted()){
    status_->setText("Adios!");
    emit delete_me(id_);
   }
   else{
    status_->setText("Algo ha salido mal...");
   }
}

bool Image_viewer::openImage(const QString &fileName){
    QImage loadedImage;
    if(!loadedImage.load(fileName))
        return false;
    else{
        image_ = loadedImage;
        if(image_.isGrayscale()){
            gray_ = true;
        }
        label_->setPixmap(QPixmap::fromImage(image_));
        resizeImage();
        layout_->addWidget(label_);
        layout_->addWidget(status_);
        setLayout(layout_);
        label_->setMouseTracking(true);
        fileName_ = fileName;
        return true;
    }
}

void Image_viewer::update_info(void){
    QVector<int> brillo_contraste = get_brillo_y_contraste();
    QVector<QString> info;
    QFileInfo fi(fileName_);

    info.resize(9);
    info[0] = fileName_;
    info[1] = fi.suffix();
    if(gray_data())
        info[2] = "gris";
    else
        info[2] = "RGB";

    int acu = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 255; j++){
            if(histograma_[i][j] != 0)
                acu++;
        }
    }
    info[3] = QString::number(acu);
    info[4] = QString::number(brillo_contraste[0]);
    info[5] = QString::number(brillo_contraste[1]);
    info[6] = QString::number(get_entropia());
    info[7] = QString::number(fi.size());
    info[8] = QString::number(id_);
    emit info_updated(info);
}

bool Image_viewer::saveImage(const QString &fileName, const char *fileFormat){
    QImage visibleImage = image_;

    if (visibleImage.save(fileName, fileFormat)) {
        return true;
    } else {
        return false;
    }
}

void Image_viewer::resizeImage(){
    QSize pixSize = label_->pixmap()->size();
    pixSize.scale(size(), Qt::KeepAspectRatio);
    label_->setFixedSize(pixSize);
    resize(label_->x(),label_->y());
}

void Image_viewer::convert_to_gray(void){
    QElapsedTimer timer;
    timer.start();
    qDebug() << "Transformando imagen a escala de grises";
    for (int ii = 0; ii < image_.height(); ii++) {
        uchar* scan = image_.scanLine(ii);
        int depth =4;
        for (int jj = 0; jj < image_.width(); jj++) {

            QRgb* rgbpixel = reinterpret_cast<QRgb*>(scan + jj*depth);
            int gray = qGray(*rgbpixel);
            *rgbpixel = QColor(gray, gray, gray).rgba();
        }
    }
    label_->setPixmap(QPixmap::fromImage(image_));
    QVector<QVector<int>> new_h = histogram_data();
    QVector<int> l;
    l.append(id_);
    new_h.append(l);
    emit histogram_updated (new_h);
}

void Image_viewer::brightness_contrast(int brillo_n, int contraste_n){
    qDebug() << "brillo y contraste de la imagen: " << get_brillo_y_contraste();
    QVector<int> data = get_brillo_y_contraste();
    int parameter_a = contraste_n / data[1];
    int parameter_b = brillo_n - parameter_a * data[0];

    qDebug() << parameter_a << " " << parameter_b;

    for (int ii = 0; ii < image_.height(); ii++) {
        uchar* scan = image_.scanLine(ii);
        int depth =4;
        for (int jj = 0; jj < image_.width(); jj++) {

            QRgb* rgbpixel = reinterpret_cast<QRgb*>(scan + jj*depth);
            int red = parameter_a * qRed(*rgbpixel) + parameter_b;
            int blue = parameter_a * qBlue(*rgbpixel) + parameter_b;
            int green = parameter_a * qGreen(*rgbpixel) + parameter_b;
            if(red > 255)
                red = 255;
            if(red < 0)
                red = 0;
            if(blue > 255)
                blue = 255;
            if(blue < 0)
                blue = 0;
            if(green > 255)
                green = 255;
            if(green < 0)
                green = 0;

            *rgbpixel = QColor(red, green, blue).rgba();
        }
    }
    label_->setPixmap(QPixmap::fromImage(image_));
    QVector<QVector<int>> new_h = histogram_data();
    QVector<int> a;
    a.append(id_);
    new_h.append(a);
    emit histogram_updated(new_h);
    qDebug() << "brillo y contraste obtenidos: " << get_brillo_y_contraste();
    update_info();
}

void Image_viewer::ecu_histogram(){
 qDebug() << "Ecualizando histograma";
 double nt = image_.width() * image_.height();
 QVector<QVector <double>> acu;
 QVector<QVector <double>> acun;
 QVector<QVector <int>> T;

 acu.resize(3);
 acu[0].resize(256);
 acu[1].resize(256);
 acu[2].resize(256);
 acun.resize(3);
 acun[0].resize(256);
 acun[1].resize(256);
 acun[2].resize(256);
 T.resize(3);
 T[0].resize(256);
 T[1].resize(256);
 T[2].resize(256);

 for(int i = 0; i < 3; i++){
     for(int j = 0; j <= 255; j++){
        if(j != 0 )
            acu[i][j] = acu[i][j-1] + histograma_[i][j];
        else
            acu[i][j] = histograma_[i][j];
        acun[i][j] = acu[i][j]/nt;
     }
 }

 for(int i = 0; i < 3; i++){
    for(int j = 0; j < 255; j++){
         int valor = acun[i][j] * 256 - 1;
         if(valor < 0)
             T[i][j] = 0;
         else
             T[i][j] = valor;
    }
 }

 for (int ii = 0; ii < image_.height(); ii++) {
     uchar* scan = image_.scanLine(ii);
     int depth =4;
     for (int jj = 0; jj < image_.width(); jj++) {

         QRgb* rgbpixel = reinterpret_cast<QRgb*>(scan + jj*depth);
         int red = T[0][qRed(*rgbpixel)];
         int green = T[1][qGreen(*rgbpixel)];
         int blue = T[2][qBlue(*rgbpixel)];
         *rgbpixel = QColor(red, green, blue).rgba();
     }
 }

 label_->setPixmap(QPixmap::fromImage(image_));
 QVector<QVector<int>> new_h = histogram_data();
 QVector<int> a;
 a.append(id_);
 new_h.append(a);
 emit histogram_updated (new_h);
 update_info();
}

void Image_viewer::gamma_correction(double a){

     for (int ii = 0; ii < image_.height(); ii++) {
         uchar* scan = image_.scanLine(ii);
         int depth =4;
         for (int jj = 0; jj < image_.width(); jj++) {

             QRgb* rgbpixel = reinterpret_cast<QRgb*>(scan + jj*depth);
             double red = double(qRed(*rgbpixel))/255;
             //qDebug()<<red;
             red= qPow(red,a);
             red=red*255;

             double green = double(qGreen(*rgbpixel))/255;
             green= qPow(green,a);
             green=green*255;
             double blue = double(qBlue(*rgbpixel))/255;
             blue= qPow(blue,a);
             blue=blue*255;

             *rgbpixel = QColor(red, green, blue).rgba();
         }
     }
     label_->setPixmap(QPixmap::fromImage(image_));
     QVector<QVector<int>> new_h = histogram_data();
     QVector<int> l;
     l.append(id_);
     new_h.append(l);
     emit histogram_updated (new_h);
}

double Image_viewer::get_entropia(void){

    int nt = image_.width() * image_.height();
    int entropia = 0;

    return entropia;
}
