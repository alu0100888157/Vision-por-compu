/********************************************************************************
** Form generated from reading UI file 'trans_lineal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANS_LINEAL_H
#define UI_TRANS_LINEAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trans_lineal
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QTabWidget *tabWidget;
    QWidget *tab_ptos;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QWidget *Tab_Graph;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *trans_lineal)
    {
        if (trans_lineal->objectName().isEmpty())
            trans_lineal->setObjectName(QStringLiteral("trans_lineal"));
        trans_lineal->resize(419, 511);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(trans_lineal->sizePolicy().hasHeightForWidth());
        trans_lineal->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(trans_lineal);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(trans_lineal);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(trans_lineal);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 29, 1, 1, 1);

        comboBox = new QComboBox(trans_lineal);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(trans_lineal);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 29, 0, 1, 1);

        label_4 = new QLabel(trans_lineal);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        label_3 = new QLabel(trans_lineal);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        lineEdit_2 = new QLineEdit(trans_lineal);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_2, 7, 1, 1, 1);

        tabWidget = new QTabWidget(trans_lineal);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tab_ptos = new QWidget();
        tab_ptos->setObjectName(QStringLiteral("tab_ptos"));
        verticalLayout_2 = new QVBoxLayout(tab_ptos);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidget = new QTableWidget(tab_ptos);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        tabWidget->addTab(tab_ptos, QString());
        Tab_Graph = new QWidget();
        Tab_Graph->setObjectName(QStringLiteral("Tab_Graph"));
        verticalLayout = new QVBoxLayout(Tab_Graph);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(Tab_Graph);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);

        tabWidget->addTab(Tab_Graph, QString());

        gridLayout->addWidget(tabWidget, 27, 0, 1, 3);

        lineEdit_3 = new QLineEdit(trans_lineal);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_3, 6, 1, 1, 1);

        label_5 = new QLabel(trans_lineal);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label = new QLabel(trans_lineal);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        pushButton = new QPushButton(trans_lineal);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 8, 1, 1, 1);


        retranslateUi(trans_lineal);
        QObject::connect(buttonBox, SIGNAL(accepted()), trans_lineal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), trans_lineal, SLOT(reject()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(trans_lineal);
    } // setupUi

    void retranslateUi(QDialog *trans_lineal)
    {
        trans_lineal->setWindowTitle(QApplication::translate("trans_lineal", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("trans_lineal", "Es necesario introducir x ptos", Q_NULLPTR));
        label_4->setText(QApplication::translate("trans_lineal", "Coordenada Y", Q_NULLPTR));
        label_3->setText(QApplication::translate("trans_lineal", "Coordenada X", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_ptos), QApplication::translate("trans_lineal", "Listado de puntos", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Tab_Graph), QApplication::translate("trans_lineal", "Gr\303\241fico", Q_NULLPTR));
        label_5->setText(QApplication::translate("trans_lineal", "Source", Q_NULLPTR));
        label->setText(QApplication::translate("trans_lineal", "N\303\272mero de tramos:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("trans_lineal", "A\303\261adir punto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trans_lineal: public Ui_trans_lineal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANS_LINEAL_H
