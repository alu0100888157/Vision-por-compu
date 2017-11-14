#ifndef IMAGE_HISTOGRAM_H
#define IMAGE_HISTOGRAM_H

//#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QDialog>
#include <QDebug>

using namespace QtCharts;

namespace Ui {
class image_histogram;
}

class image_histogram : public QDialog
{
    Q_OBJECT

public:
    explicit image_histogram(QWidget *parent = 0);
    void add_selection(QString option);
    void add_histogram(QVector<QVector<int>> data);
    void add_gray(bool gray);
    void set_mode(bool mode);
    bool is_gray(int index);
    ~image_histogram();

public slots:
    void actualizar_histograma(QVector<QVector<int>>);

private slots:
    void on_image_selector_activated(int index);

private:
    bool mode_;
    Ui::image_histogram *ui;
    QVector<QVector<QVector<int>>> histogramas_;
    QVector<bool> is_gray_;
    QVector<int> brillo_;
    QVector<int> contraste_;
    void draw_normal(int index);
    void draw_ac(int index);
};

#endif // IMAGE_HISTOGRAM_H
