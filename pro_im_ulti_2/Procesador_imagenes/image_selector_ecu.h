#ifndef IMAGE_SELECTOR_ECU_H
#define IMAGE_SELECTOR_ECU_H

#include <QDialog>

namespace Ui {
class image_selector_ecu;
}

class image_selector_ecu : public QDialog
{
    Q_OBJECT

public:
    explicit image_selector_ecu(QWidget *parent = 0);
     void add_selection(QString option);
    ~image_selector_ecu();

signals:
    void image_selected(int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::image_selector_ecu *ui;
};

#endif // IMAGE_SELECTOR_ECU_H
