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

void image_info::on_Image_selector_activated(int index){
    ui_->c1->setText(info_[index][0]);
    ui_->c2->setText(info_[index][1]);
    ui_->c3->setText(info_[index][2]);
    ui_->c4->setText(info_[index][3]);
    ui_->c5->setText(info_[index][4]);
    ui_->c6->setText(info_[index][5]);
    ui_->c7->setText(info_[index][6]);
    ui_->c8->setText(info_[index][7]);
}

void image_info::info_updated(QVector<QString> data){
    int index = data[8].toInt();
    qDebug() << data;
    info_.resize(info_.size()+1);
    info_[index] = data;
}

QStringList image_info::aviable_images(void){
   return images_;
}

