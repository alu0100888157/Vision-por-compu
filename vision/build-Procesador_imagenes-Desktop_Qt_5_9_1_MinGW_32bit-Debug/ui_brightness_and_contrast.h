/********************************************************************************
** Form generated from reading UI file 'brightness_and_contrast.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESS_AND_CONTRAST_H
#define UI_BRIGHTNESS_AND_CONTRAST_H

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
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Brightness_and_contrast
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox;

    void setupUi(QDialog *Brightness_and_contrast)
    {
        if (Brightness_and_contrast->objectName().isEmpty())
            Brightness_and_contrast->setObjectName(QStringLiteral("Brightness_and_contrast"));
        Brightness_and_contrast->resize(400, 162);
        gridLayout = new QGridLayout(Brightness_and_contrast);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(Brightness_and_contrast);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(Brightness_and_contrast);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Brightness_and_contrast);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 2, 1, 1);

        label = new QLabel(Brightness_and_contrast);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit = new QLineEdit(Brightness_and_contrast);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 2, 1, 1);

        lineEdit_2 = new QLineEdit(Brightness_and_contrast);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 2, 1, 1);

        comboBox = new QComboBox(Brightness_and_contrast);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);


        retranslateUi(Brightness_and_contrast);
        QObject::connect(buttonBox, SIGNAL(accepted()), Brightness_and_contrast, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Brightness_and_contrast, SLOT(reject()));

        QMetaObject::connectSlotsByName(Brightness_and_contrast);
    } // setupUi

    void retranslateUi(QDialog *Brightness_and_contrast)
    {
        Brightness_and_contrast->setWindowTitle(QApplication::translate("Brightness_and_contrast", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("Brightness_and_contrast", "Contraste:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Brightness_and_contrast", "Source", Q_NULLPTR));
        label->setText(QApplication::translate("Brightness_and_contrast", "Brillo:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Brightness_and_contrast: public Ui_Brightness_and_contrast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESS_AND_CONTRAST_H
