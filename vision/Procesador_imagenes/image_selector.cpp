#include "image_selector.h"
#include "ui_image_selector.h"

image_selector::image_selector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image_selector)
{
    ui->setupUi(this);
}

image_selector::~image_selector()
{
    delete ui;
}
