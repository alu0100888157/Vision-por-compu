#include "image_selector_ecu.h"
#include "ui_image_selector_ecu.h"

image_selector_ecu::image_selector_ecu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image_selector_ecu)
{
    ui->setupUi(this);
}

image_selector_ecu::~image_selector_ecu()
{
    delete ui;
}

void image_selector_ecu::add_selection(QString option){
    ui->image_selector->addItem(option);
}

void image_selector_ecu::on_buttonBox_accepted(){
    emit image_selected(ui->image_selector->currentIndex());
}
