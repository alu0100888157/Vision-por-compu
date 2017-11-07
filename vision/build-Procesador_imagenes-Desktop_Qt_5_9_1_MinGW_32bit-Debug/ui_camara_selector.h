/********************************************************************************
** Form generated from reading UI file 'camara_selector.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMARA_SELECTOR_H
#define UI_CAMARA_SELECTOR_H

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
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_camara_selector
{
public:
    QGridLayout *gridLayout;
    QComboBox *select_device;
    QLabel *label_dispositivo;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *camara_selector)
    {
        if (camara_selector->objectName().isEmpty())
            camara_selector->setObjectName(QStringLiteral("camara_selector"));
        camara_selector->resize(268, 140);
        gridLayout = new QGridLayout(camara_selector);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        select_device = new QComboBox(camara_selector);
        select_device->setObjectName(QStringLiteral("select_device"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(select_device->sizePolicy().hasHeightForWidth());
        select_device->setSizePolicy(sizePolicy);

        gridLayout->addWidget(select_device, 0, 1, 1, 1);

        label_dispositivo = new QLabel(camara_selector);
        label_dispositivo->setObjectName(QStringLiteral("label_dispositivo"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_dispositivo->sizePolicy().hasHeightForWidth());
        label_dispositivo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_dispositivo, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(camara_selector);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(camara_selector);
        QObject::connect(buttonBox, SIGNAL(accepted()), camara_selector, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), camara_selector, SLOT(reject()));

        QMetaObject::connectSlotsByName(camara_selector);
    } // setupUi

    void retranslateUi(QDialog *camara_selector)
    {
        camara_selector->setWindowTitle(QApplication::translate("camara_selector", "Selecci\303\263n de c\303\241mara", Q_NULLPTR));
        label_dispositivo->setText(QApplication::translate("camara_selector", "Dispositivo:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class camara_selector: public Ui_camara_selector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMARA_SELECTOR_H
