#include "image_selector_dif.h"
#include "ui_image_selector_dif.h"

image_selector_dif::image_selector_dif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image_selector_dif)
{
    ui->setupUi(this);
}

image_selector_dif::~image_selector_dif()
{
    delete ui;
}
