#ifndef BRIGHTNESS_AND_CONTRAST_H
#define BRIGHTNESS_AND_CONTRAST_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Brightness_and_contrast;
}

class Brightness_and_contrast : public QDialog
{
    Q_OBJECT

public:
    explicit Brightness_and_contrast(QWidget *parent = 0);
    void add_selection(QString option);
    ~Brightness_and_contrast();

signals:
    void image_selected(QVector<int>);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Brightness_and_contrast *ui;
};

#endif // BRIGHTNESS_AND_CONTRAST_H
