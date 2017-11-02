#include "trans_lineal.h"
#include "ui_trans_lineal.h"

trans_lineal::trans_lineal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trans_lineal)
{
    ui->setupUi(this);
}

trans_lineal::~trans_lineal()
{
    delete ui;
}
