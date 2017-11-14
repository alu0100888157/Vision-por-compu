#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QList<QCameraInfo> info, QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog),
    lista(info){

    ui->setupUi(this);
    ui->caja_dispositivo->addItem(tr("Default"));

    foreach (const QCameraInfo &cameraInfo, info) {
        ui->caja_dispositivo->addItem(QString(cameraInfo.deviceName()));
    }
}

Dialog::~Dialog()
{
    delete ui;
}

QCameraInfo Dialog::init(void){
   return informacion;
}


void Dialog::on_caja_dispositivo_activated(int index){
    if(index == 0)
        informacion = lista[index];
    else
        informacion = lista[index-1];
}
