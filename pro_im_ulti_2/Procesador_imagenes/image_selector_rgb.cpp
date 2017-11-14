#include "image_selector_rgb.h"
#include "ui_image_selector_rgb.h"

image_selector_rgb::image_selector_rgb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image_selector_rgb)
{
    ui->setupUi(this);
}

image_selector_rgb::~image_selector_rgb()
{
    delete ui;
}
