#ifndef BRIGHTNESS_AND_CONTRAST_H
#define BRIGHTNESS_AND_CONTRAST_H

#include <QDialog>

namespace Ui {
class Brightness_and_contrast;
}

class Brightness_and_contrast : public QDialog
{
    Q_OBJECT

public:
    explicit Brightness_and_contrast(QWidget *parent = 0);
    ~Brightness_and_contrast();

private:
    Ui::Brightness_and_contrast *ui;
};

#endif // BRIGHTNESS_AND_CONTRAST_H
