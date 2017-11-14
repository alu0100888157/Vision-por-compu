#ifndef MAINGUI_H
#define MAINGUI_H

#include <QDebug>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QSettings>

#include "brightness_and_contrast.h"
#include "image_histogram.h"
#include "image_info.h"
#include "image_selector_gray.h"
#include "image_selector_ecu.h"
#include "image_selector_gamma.h"
#include "image_viewer.h"

namespace Ui {
    class MainGui;
}

class MainGui : public QMainWindow{                 // Clase Principal.
    Q_OBJECT

public:
    explicit MainGui(QWidget *parent = 0);          // Constructor.
    void loadFile(const QString &fileName);         // Función de carga de archivo.
    ~MainGui();

protected:
    void closeEvent(QCloseEvent *event) override;   // Redefinición de la función de manejo del evento de cierre de una ventana.

public slots:
    void gray_Convert(int);
    void brightness_Contrast(QVector<int>);
    void ecua_histogram(int);
    void gamma_correction(QVector<double>);

private slots:
    void open();
    bool save();
    bool saveAs();
    void about();
    void imageWasModified();

    void showInfo();
    void showHistogram();
    void showHistogramAc();

    void transLineal();
    void brightnessContrast();
    void ecu();
    void gamma();
    void grayConvert();

private:
    Ui::MainGui *ui_;
    QList<Image_viewer*> viewers_;
    Brightness_and_contrast b_and_c_;
    image_info information_;
    image_histogram histogram_;
    Image_selector_gray selector_gray_;
    image_selector_ecu selector_ecu_;
    image_selector_gamma selector_gamma_;
    QString curFile_;
    QStringList data_;
    quint8 counter_;

    void writeSettings();
    void readSettings();

    void createActions();
    void createStatusBar();

    void setCurrentImage(const QString &fileName);
    bool saveImage(const QString &fileName);

    void transformacion_lineal(QVector<int> data);
    void terminate();
};

#endif // MAINGUI_H
