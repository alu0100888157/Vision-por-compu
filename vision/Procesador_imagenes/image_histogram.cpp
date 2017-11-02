#include "image_histogram.h"
#include "ui_image_histogram.h"

image_histogram::image_histogram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image_histogram){
    ui->setupUi(this);
}

void image_histogram::add_selection(QString option){
    ui->image_selector->addItem(option);
}

void image_histogram::add_histogram(QVector<QVector<int>> data){
    qDebug() << data;
    histogramas_.append(data);
}

void image_histogram::add_gray(bool gray){
    is_gray_.append(gray);
}

void image_histogram::set_mode(bool mode){
    mode_ = mode;
}

void image_histogram::brillo(void){
    int brillo = 0;
    int pixeles = 0;
    int index = 0;

    for(int i = 0; i < 255; i++){
        brillo += i * histogramas_[index][0][i];
        pixeles += histogramas_[index][0][i];
    }

    brillo = brillo / pixeles;

}

void image_histogram::contraste(void){
    for(int i = 0; i < 255; i++){
    int contraste = 0;
    int pixeles = 0;

    /*for(int i = 0; i < 255; i++){
        contraste += (i - brillo) * (i - brillo) * histogramas_[index][0][i];
        pixeles += histogramas_[index][0][i];
    }

    contraste = contraste / pixeles;

    contraste = qSqrt(contraste);*/
    }

}

bool image_histogram::is_gray(int index){
    return is_gray_[index];
}

image_histogram::~image_histogram(){
    delete ui;
}

void image_histogram::on_image_selector_activated(int index){
    if(mode_){
        draw_normal(index);
    }
    else{
        draw_ac(index);
    }
}

void image_histogram::draw_normal(int index){
    if(is_gray_[index]){
        ui->R->hide();
        ui->G->hide();
        ui->B->setTitle("Gray");
        QBarSet *gray_set = new QBarSet("Gris");
        gray_set->setColor(QColor(0,0,0));
        for(int i = 0; i < 255; i++)
            *gray_set << histogramas_[index][0][i];
        QBarSeries *serie = new QBarSeries();
        serie->append(gray_set);
        serie->setBarWidth(1);

        QChart *chart = new QChart();
        chart->addSeries(serie);
        chart->setTitle("Histograma niveles de gris");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->createDefaultAxes();

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget->setChart(chart);
        ui->widget->setRenderHint(QPainter::Antialiasing);
    }
    else{
        ui->R->setTitle("Red");
        QBarSet *red_set = new QBarSet("Rojo");
        red_set->setColor(QColor(255,0,0));
        for(int i = 0; i < 255; i++)
            *red_set << histogramas_[index][0][i];
        QBarSeries *rserie = new QBarSeries();
        rserie->append(red_set);
        rserie->setBarWidth(1);

        QChart *rchart = new QChart();
        rchart->addSeries(rserie);
        rchart->setTitle("Histograma niveles de rojo");
        rchart->setAnimationOptions(QChart::SeriesAnimations);
        rchart->createDefaultAxes();

        rchart->legend()->setVisible(true);
        rchart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget_3->setChart(rchart);
        ui->widget_3->setRenderHint(QPainter::Antialiasing);

        ui->G->setTitle("Green");
        QBarSet *green_set = new QBarSet("Verde");
        green_set->setColor(QColor(0,255,0));
        for(int i = 0; i < 255; i++)
            *green_set << histogramas_[index][1][i];
        QBarSeries *gserie = new QBarSeries();
        gserie->append(green_set);
        gserie->setBarWidth(1);

        QChart *gchart = new QChart();
        gchart->addSeries(gserie);
        gchart->setTitle("Histograma niveles de verde");
        gchart->setAnimationOptions(QChart::SeriesAnimations);
        gchart->createDefaultAxes();

        gchart->legend()->setVisible(true);
        gchart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget_2->setChart(gchart);
        ui->widget_2->setRenderHint(QPainter::Antialiasing);


        ui->B->setTitle("Blue");
        QBarSet *blue_set = new QBarSet("Azul");
        blue_set->setColor(QColor(0,0,255));
        for(int i = 0; i < 255; i++)
            *blue_set << histogramas_[index][2][i];
        QBarSeries *bserie = new QBarSeries();
        bserie->append(blue_set);
        bserie->setBarWidth(1);

        QChart *bchart = new QChart();
        bchart->addSeries(bserie);
        bchart->setTitle("Histograma niveles de azul");
        bchart->setAnimationOptions(QChart::SeriesAnimations);
        bchart->createDefaultAxes();

        bchart->legend()->setVisible(true);
        bchart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget->setChart(bchart);
        ui->widget->setRenderHint(QPainter::Antialiasing);
    }
}

QVector<int> image_histogram::histograma_acumulado_normalizado(int index){
    QVector<int> histograma;
    histograma.resize(256);

    int ac = 0;
    for(int i = 0; i < 255; i++){
        ac += histogramas_[index][0][i] / histogramas_[index][0][255];
        histograma[i] = ac;
    }
}

void image_histogram::draw_ac(int index){
    if(is_gray_[index]){
        ui->R->hide();
        ui->G->hide();
        ui->B->setTitle("Gray");
        QBarSet *gray_set = new QBarSet("Gris");
        gray_set->setColor(QColor(0,0,0));
        int ac = 0;
        for(int i = 0; i < 255; i++){
            ac += histogramas_[index][0][i];
            *gray_set << ac;
        }
        QBarSeries *serie = new QBarSeries();
        serie->append(gray_set);
        serie->setBarWidth(1);

        QChart *chart = new QChart();
        chart->addSeries(serie);
        chart->setTitle("Histograma niveles de gris");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->createDefaultAxes();

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget->setChart(chart);
        ui->widget->setRenderHint(QPainter::Antialiasing);
    }
    else{
        ui->R->setTitle("Red");
        QBarSet *red_set = new QBarSet("Rojo");
        red_set->setColor(QColor(255,0,0));
        int acr = 0;
        for(int i = 0; i < 255; i++){
            acr += histogramas_[index][0][i];
            *red_set << acr;
        }
        QBarSeries *rserie = new QBarSeries();
        rserie->append(red_set);
        rserie->setBarWidth(1);

        QChart *rchart = new QChart();
        rchart->addSeries(rserie);
        rchart->setTitle("Histograma niveles de rojo");
        rchart->setAnimationOptions(QChart::SeriesAnimations);
        rchart->createDefaultAxes();

        rchart->legend()->setVisible(true);
        rchart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget_3->setChart(rchart);
        ui->widget_3->setRenderHint(QPainter::Antialiasing);

        ui->G->setTitle("Green");
        QBarSet *green_set = new QBarSet("Verde");
        green_set->setColor(QColor(0,255,0));
        int acg = 0;
        for(int i = 0; i < 255; i++){
            acg += histogramas_[index][1][i];
            *green_set << acg;
        }
        QBarSeries *gserie = new QBarSeries();
        gserie->append(green_set);
        gserie->setBarWidth(1);

        QChart *gchart = new QChart();
        gchart->addSeries(gserie);
        gchart->setTitle("Histograma niveles de verde");
        gchart->setAnimationOptions(QChart::SeriesAnimations);
        gchart->createDefaultAxes();

        gchart->legend()->setVisible(true);
        gchart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget_2->setChart(gchart);
        ui->widget_2->setRenderHint(QPainter::Antialiasing);


        ui->B->setTitle("Blue");
        QBarSet *blue_set = new QBarSet("Azul");
        blue_set->setColor(QColor(0,0,255));
        int acb = 0;
        for(int i = 0; i < 255; i++){
            acb += histogramas_[index][2][i];
            *blue_set << acb;
        }
        QBarSeries *bserie = new QBarSeries();
        bserie->append(blue_set);
        bserie->setBarWidth(1);

        QChart *bchart = new QChart();
        bchart->addSeries(bserie);
        bchart->setTitle("Histograma niveles de azul");
        bchart->setAnimationOptions(QChart::SeriesAnimations);
        bchart->createDefaultAxes();

        bchart->legend()->setVisible(true);
        bchart->legend()->setAlignment(Qt::AlignBottom);

        ui->widget->setChart(bchart);
        ui->widget->setRenderHint(QPainter::Antialiasing);
    }
}
