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

void Brightness_and_contrast::add_selection(QString option){
    ui->Image_selector->addItem(option);
}

void Brightness_and_contrast::on_buttonBox_accepted(){
    if(!ui->line_brillo->text().isEmpty() && !ui->line_brillo->text().isEmpty()){
        QVector<int> data;
        data.append(ui->Image_selector->currentIndex());
        data.append(ui->line_brillo->text().toInt());
        data.append(ui->line_contraste->text().toInt());

        emit image_selected(data);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Los valores introducidos no son correctos.");
        msgBox.exec();
    }
}
