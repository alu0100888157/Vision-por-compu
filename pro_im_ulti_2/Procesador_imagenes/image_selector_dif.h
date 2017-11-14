#ifndef IMAGE_SELECTOR_DIF_H
#define IMAGE_SELECTOR_DIF_H

#include <QDialog>

namespace Ui {
class image_selector_dif;
}

class image_selector_dif : public QDialog
{
    Q_OBJECT

public:
    explicit image_selector_dif(QWidget *parent = 0);
    ~image_selector_dif();

private:
    Ui::image_selector_dif *ui;
};

#endif // IMAGE_SELECTOR_DIF_H
