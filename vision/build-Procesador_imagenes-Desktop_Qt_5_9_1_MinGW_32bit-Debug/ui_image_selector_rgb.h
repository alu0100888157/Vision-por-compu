/********************************************************************************
** Form generated from reading UI file 'image_selector_rgb.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_SELECTOR_RGB_H
#define UI_IMAGE_SELECTOR_RGB_H

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

class Ui_image_selector_rgb
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *image_selector_rgb)
    {
        if (image_selector_rgb->objectName().isEmpty())
            image_selector_rgb->setObjectName(QStringLiteral("image_selector_rgb"));
        image_selector_rgb->resize(277, 159);
        gridLayout = new QGridLayout(image_selector_rgb);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox = new QComboBox(image_selector_rgb);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        comboBox_2 = new QComboBox(image_selector_rgb);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(image_selector_rgb);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);

        label = new QLabel(image_selector_rgb);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(image_selector_rgb);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(image_selector_rgb);
        QObject::connect(buttonBox, SIGNAL(accepted()), image_selector_rgb, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), image_selector_rgb, SLOT(reject()));

        QMetaObject::connectSlotsByName(image_selector_rgb);
    } // setupUi

    void retranslateUi(QDialog *image_selector_rgb)
    {
        image_selector_rgb->setWindowTitle(QApplication::translate("image_selector_rgb", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("image_selector_rgb", "Imagen:", Q_NULLPTR));
        label_2->setText(QApplication::translate("image_selector_rgb", "Codificaci\303\263n:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class image_selector_rgb: public Ui_image_selector_rgb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_SELECTOR_RGB_H
