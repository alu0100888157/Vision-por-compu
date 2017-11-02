#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCameraInfo>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QList<QCameraInfo> info, QWidget *parent = 0);
    ~Dialog();

    QCameraInfo init(void);
private slots:

    void on_caja_dispositivo_activated(int index);

private:
    Ui::Dialog *ui;

   QList<QCameraInfo> lista;

   QCameraInfo informacion;
};

#endif // DIALOG_H
