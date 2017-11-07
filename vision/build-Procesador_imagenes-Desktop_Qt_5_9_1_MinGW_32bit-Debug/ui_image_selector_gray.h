/********************************************************************************
** Form generated from reading UI file 'image_selector_gray.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_SELECTOR_GRAY_H
#define UI_IMAGE_SELECTOR_GRAY_H

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

class Ui_Image_selector_gray
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Image_selector_gray)
    {
        if (Image_selector_gray->objectName().isEmpty())
            Image_selector_gray->setObjectName(QStringLiteral("Image_selector_gray"));
        Image_selector_gray->resize(184, 132);
        gridLayout = new QGridLayout(Image_selector_gray);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(Image_selector_gray);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        label = new QLabel(Image_selector_gray);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(Image_selector_gray);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(Image_selector_gray);
        QObject::connect(buttonBox, SIGNAL(accepted()), Image_selector_gray, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Image_selector_gray, SLOT(reject()));

        QMetaObject::connectSlotsByName(Image_selector_gray);
    } // setupUi

    void retranslateUi(QDialog *Image_selector_gray)
    {
        Image_selector_gray->setWindowTitle(QApplication::translate("Image_selector_gray", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Image_selector_gray", "Imagen:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Image_selector_gray: public Ui_Image_selector_gray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_SELECTOR_GRAY_H
