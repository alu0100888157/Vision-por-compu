#ifndef IMAGE_SELECTOR_RGB_H
#define IMAGE_SELECTOR_RGB_H

#include <QDialog>

namespace Ui {
class image_selector_rgb;
}

class image_selector_rgb : public QDialog
{
    Q_OBJECT

public:
    explicit image_selector_rgb(QWidget *parent = 0);
    ~image_selector_rgb();

signals:
    void image_selected(QVector<int>);

private:
    Ui::image_selector_rgb *ui;
};

#endif // IMAGE_SELECTOR_RGB_H
