#ifndef IMAGE_DIALOG_H
#define IMAGE_DIALOG_H

#include <QDialog>

namespace Ui {
class image_dialog;
}

class image_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit image_dialog(QWidget *parent = 0);
    ~image_dialog();

private:
    Ui::image_dialog *ui;
};

#endif // IMAGE_DIALOG_H
