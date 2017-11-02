#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCameraInfo>

namespace Ui {
class camara_selector;
}

class camara_selector : public QDialog
{
    Q_OBJECT

public:
    explicit camara_selector(QList<QCameraInfo> info, QWidget *parent = 0);
    ~camara_selector();

    QCameraInfo init(void);

private slots:
    void on_select_device_currentIndexChanged(int index);

private:
   Ui::camara_selector *ui;

   QList<QCameraInfo> lista;
   QCameraInfo informacion;
};

#endif // DIALOG_H
