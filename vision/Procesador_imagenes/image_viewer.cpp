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

    return data;
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
        return true;
    }
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
