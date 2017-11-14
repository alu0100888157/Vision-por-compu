#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEWER_H

#include <QElapsedTimer>
#include <QFileInfo>
#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QStatusBar>
#include <QtMath>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>
#include <math.h>


class Image_viewer : public QWidget{
    Q_OBJECT

public:
    explicit Image_viewer(qint8 id, QString name, QWidget *parent = 0);
    QVector<int> get_brillo_y_contraste(void);
    void update_info(void);
    double get_entropia(void);
    bool gray_data(void);
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void mouseMoveEvent(QMouseEvent *event);

    void convert_to_gray(void);
    void brightness_contrast(int brillo_n, int contraste_f);
    void ecu_histogram();
    void gamma_correction(double);

    QVector<QVector<int>> histogram_data(void);
signals:
    delete_me(qint8 id);
    histogram_updated(QVector<QVector<int>> data);
    info_updated(QVector<QString> data);

protected:
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event) override;

private:
    bool gray_;
    quint8 id_;
    QString fileName_;
    QVBoxLayout *layout_;
    QImage image_;
    QLabel *label_;
    QLabel *status_;

     QVector<QVector<int>> histograma_;
     QVector<QString> info_;

    void resizeImage();
};

#endif // IMAGE_VIEWER_H
