#ifndef IMAGE_SELECTOR_GRAY_H
#define IMAGE_SELECTOR_GRAY_H

#include <QDialog>

namespace Ui {
class Image_selector_gray;
}

class Image_selector_gray : public QDialog
{
    Q_OBJECT

public:
    explicit Image_selector_gray(QWidget *parent = 0);
     void add_selection(QString option);
    ~Image_selector_gray();

signals:
    void image_selected(int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Image_selector_gray *ui;
};

#endif // IMAGE_SELECTOR_GRAY_H
