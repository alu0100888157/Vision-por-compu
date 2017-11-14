#include "camara_selector.h"
#include "ui_camara_selector.h"

camara_selector::camara_selector(QList<QCameraInfo> info, QWidget *parent):
    QDialog(parent),
    ui(new Ui::camara_selector),
    lista(info){

    ui->setupUi(this);
    /*ui->caja_dispositivo->addItem(tr("Default"));

    foreach (const QCameraInfo &cameraInfo, info) {
        ui->caja_dispositivo->addItem(QString(cameraInfo.deviceName()));
    }*/
}

camara_selector::~camara_selector(){
    delete ui;
}

QCameraInfo camara_selector::init(void){
   return informacion;
}


/*void camara_selector::on_caja_dispositivo_activated(int index){
    if(index == 0)
        informacion = lista[index];
    else
        informacion = lista[index-1];
}*/
