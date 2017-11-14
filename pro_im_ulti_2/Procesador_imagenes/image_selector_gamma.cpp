#include "image_selector_gamma.h"
#include "ui_image_selector_gamma.h"

image_selector_gamma::image_selector_gamma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image_selector_gamma)
{
    ui->setupUi(this);
}

image_selector_gamma::~image_selector_gamma()
{
    delete ui;
}

void image_selector_gamma::add_selection(QString option){
    ui->image_selector->addItem(option);
}

void image_selector_gamma::on_buttonBox_accepted(){
    QVector<double> vector;

    vector.append(ui->image_selector->currentIndex());
    vector.append(ui->gamma->text().toDouble());
    emit image_selected(vector);
}
