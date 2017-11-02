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
    ~Image_selector_gray();

private:
    Ui::Image_selector_gray *ui;
};

#endif // IMAGE_SELECTOR_GRAY_H
