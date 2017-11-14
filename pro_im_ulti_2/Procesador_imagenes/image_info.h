#ifndef IMAGE_INFO_H
#define IMAGE_INFO_H

#include <QDebug>
#include <QDialog>
#include <QVector>

namespace Ui {
    class image_info;
}

class image_info : public QDialog{
    Q_OBJECT

public:
    explicit image_info(QWidget *parent = 0);
    void add_selection(QString option);
    QStringList aviable_images(void);

public slots:
    void info_updated(QVector<QString>);

private slots:
    void on_Image_selector_activated(int index);

private:
    Ui::image_info *ui_;
    QStringList images_;
    QVector< QVector<QString>> info_;
};

#endif // IMAGE_INFO_H
