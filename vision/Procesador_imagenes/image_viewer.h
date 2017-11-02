#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEWER_H

#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QStatusBar>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QVBoxLayout>
#include <QWidget>


class Image_viewer : public QWidget{
    Q_OBJECT

public:
    explicit Image_viewer(qint8 id, QString name, QWidget *parent = 0);
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void mouseMoveEvent(QMouseEvent *event);
    QVector<QVector<int>> histogram_data(void);
    bool gray_data(void);

signals:
    delete_me(qint8 id);

protected:
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event) override;

private:
    void resizeImage();

    quint8 id_;
    QVBoxLayout *layout_;
    QImage image_;
    QLabel *label_;
    QLabel *status_;
    bool gray_;
};

#endif // IMAGE_VIEWER_H
