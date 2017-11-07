/********************************************************************************
** Form generated from reading UI file 'image_histogram.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_HISTOGRAM_H
#define UI_IMAGE_HISTOGRAM_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_image_histogram
{
public:
    QGridLayout *gridLayout;
    QComboBox *image_selector;
    QLabel *label;
    QGroupBox *R;
    QVBoxLayout *verticalLayout;
    QtCharts::QChartView *widget_3;
    QGroupBox *G;
    QVBoxLayout *verticalLayout_2;
    QtCharts::QChartView *widget_2;
    QGroupBox *B;
    QVBoxLayout *verticalLayout_3;
    QtCharts::QChartView *widget;

    void setupUi(QDialog *image_histogram)
    {
        if (image_histogram->objectName().isEmpty())
            image_histogram->setObjectName(QStringLiteral("image_histogram"));
        image_histogram->resize(878, 570);
        gridLayout = new QGridLayout(image_histogram);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        image_selector = new QComboBox(image_histogram);
        image_selector->setObjectName(QStringLiteral("image_selector"));

        gridLayout->addWidget(image_selector, 0, 1, 1, 1);

        label = new QLabel(image_histogram);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        R = new QGroupBox(image_histogram);
        R->setObjectName(QStringLiteral("R"));
        verticalLayout = new QVBoxLayout(R);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QtCharts::QChartView(R);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        verticalLayout->addWidget(widget_3);


        gridLayout->addWidget(R, 1, 0, 1, 2);

        G = new QGroupBox(image_histogram);
        G->setObjectName(QStringLiteral("G"));
        verticalLayout_2 = new QVBoxLayout(G);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QtCharts::QChartView(G);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        verticalLayout_2->addWidget(widget_2);


        gridLayout->addWidget(G, 2, 0, 1, 2);

        B = new QGroupBox(image_histogram);
        B->setObjectName(QStringLiteral("B"));
        verticalLayout_3 = new QVBoxLayout(B);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QtCharts::QChartView(B);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_3->addWidget(widget);


        gridLayout->addWidget(B, 3, 0, 1, 2);


        retranslateUi(image_histogram);

        QMetaObject::connectSlotsByName(image_histogram);
    } // setupUi

    void retranslateUi(QDialog *image_histogram)
    {
        image_histogram->setWindowTitle(QApplication::translate("image_histogram", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("image_histogram", "Source:", Q_NULLPTR));
        R->setTitle(QApplication::translate("image_histogram", "Red", Q_NULLPTR));
        G->setTitle(QApplication::translate("image_histogram", "Green", Q_NULLPTR));
        B->setTitle(QApplication::translate("image_histogram", "Blue", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class image_histogram: public Ui_image_histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_HISTOGRAM_H
