#ifndef IMAGE_SELECTOR_GAMMA_H
#define IMAGE_SELECTOR_GAMMA_H

#include <QDialog>

namespace Ui {
class image_selector_gamma;
}

class image_selector_gamma : public QDialog
{
    Q_OBJECT

public:
    explicit image_selector_gamma(QWidget *parent = 0);
    void add_selection(QString option);
    ~image_selector_gamma();

signals:
    void image_selected(QVector<double>);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::image_selector_gamma *ui;
};

#endif // IMAGE_SELECTOR_GAMMA_H
