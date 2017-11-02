#include "brightness_and_contrast.h"
#include "ui_brightness_and_contrast.h"

Brightness_and_contrast::Brightness_and_contrast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Brightness_and_contrast)
{
    ui->setupUi(this);
}

Brightness_and_contrast::~Brightness_and_contrast()
{
    delete ui;
}
