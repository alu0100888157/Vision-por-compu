#ifndef TRANS_LINEAL_H
#define TRANS_LINEAL_H

#include <QDialog>

namespace Ui {
class trans_lineal;
}

class trans_lineal : public QDialog
{
    Q_OBJECT

public:
    explicit trans_lineal(QWidget *parent = 0);
    ~trans_lineal();

private:
    Ui::trans_lineal *ui;
};

#endif // TRANS_LINEAL_H
