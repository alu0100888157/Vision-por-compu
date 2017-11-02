#include "image_selector_gray.h"
#include "ui_image_selector_gray.h"

Image_selector_gray::Image_selector_gray(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Image_selector_gray)
{
    ui->setupUi(this);
}

Image_selector_gray::~Image_selector_gray()
{
    delete ui;
}
