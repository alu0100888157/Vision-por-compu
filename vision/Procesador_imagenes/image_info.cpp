#include "image_info.h"
#include "ui_image_info.h"

image_info::image_info(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::image_info){
    ui_->setupUi(this);
}

void image_info::add_selection(QString option){
    images_.append(option);
    ui_->Image_selector->addItem(option);
}

void image_info::add_stringList(QStringList data){
    info_ << data;   // formato de la lista data:
                    //      [nombre, formato, tamaño, dimensiones, mono/RGB, num. colores, color actual]
}


void image_info::on_Image_selector_activated(int index){

}

QStringList image_info::aviable_images(void){
   return images_;
}
