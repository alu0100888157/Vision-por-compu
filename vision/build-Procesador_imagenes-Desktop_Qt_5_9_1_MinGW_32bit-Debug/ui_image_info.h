/********************************************************************************
** Form generated from reading UI file 'image_info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_INFO_H
#define UI_IMAGE_INFO_H

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

class Ui_image_info
{
public:
    QGridLayout *gridLayout;
    QGroupBox *Advanced_box;
    QVBoxLayout *verticalLayout_2;
    QLabel *MoRGB_label;
    QLabel *Ncolor_label;
    QLabel *label_5;
    QLabel *label;
    QComboBox *Image_selector;
    QLabel *IMG;
    QGroupBox *Basic_box;
    QVBoxLayout *verticalLayout;
    QLabel *name_label;
    QLabel *format_label;

    void setupUi(QDialog *image_info)
    {
        if (image_info->objectName().isEmpty())
            image_info->setObjectName(QStringLiteral("image_info"));
        image_info->resize(365, 401);
        gridLayout = new QGridLayout(image_info);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Advanced_box = new QGroupBox(image_info);
        Advanced_box->setObjectName(QStringLiteral("Advanced_box"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Advanced_box->sizePolicy().hasHeightForWidth());
        Advanced_box->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(Advanced_box);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        MoRGB_label = new QLabel(Advanced_box);
        MoRGB_label->setObjectName(QStringLiteral("MoRGB_label"));

        verticalLayout_2->addWidget(MoRGB_label);

        Ncolor_label = new QLabel(Advanced_box);
        Ncolor_label->setObjectName(QStringLiteral("Ncolor_label"));

        verticalLayout_2->addWidget(Ncolor_label);

        label_5 = new QLabel(Advanced_box);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label = new QLabel(Advanced_box);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);


        gridLayout->addWidget(Advanced_box, 2, 0, 1, 2);

        Image_selector = new QComboBox(image_info);
        Image_selector->setObjectName(QStringLiteral("Image_selector"));

        gridLayout->addWidget(Image_selector, 0, 0, 1, 2);

        IMG = new QLabel(image_info);
        IMG->setObjectName(QStringLiteral("IMG"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(IMG->sizePolicy().hasHeightForWidth());
        IMG->setSizePolicy(sizePolicy1);
        IMG->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/Imagenes_GUI/info.png")));
        IMG->setScaledContents(false);
        IMG->setWordWrap(false);

        gridLayout->addWidget(IMG, 1, 0, 1, 1);

        Basic_box = new QGroupBox(image_info);
        Basic_box->setObjectName(QStringLiteral("Basic_box"));
        sizePolicy.setHeightForWidth(Basic_box->sizePolicy().hasHeightForWidth());
        Basic_box->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Basic_box);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name_label = new QLabel(Basic_box);
        name_label->setObjectName(QStringLiteral("name_label"));

        verticalLayout->addWidget(name_label);

        format_label = new QLabel(Basic_box);
        format_label->setObjectName(QStringLiteral("format_label"));

        verticalLayout->addWidget(format_label);


        gridLayout->addWidget(Basic_box, 1, 1, 1, 1);


        retranslateUi(image_info);

        QMetaObject::connectSlotsByName(image_info);
    } // setupUi

    void retranslateUi(QDialog *image_info)
    {
        image_info->setWindowTitle(QApplication::translate("image_info", "Dialog", Q_NULLPTR));
        Advanced_box->setTitle(QApplication::translate("image_info", "Informaci\303\263n avanzada", Q_NULLPTR));
        MoRGB_label->setText(QApplication::translate("image_info", "Mono. o RGB: ", Q_NULLPTR));
        Ncolor_label->setText(QApplication::translate("image_info", "N\303\272mero de colores: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("image_info", "Brillo:", Q_NULLPTR));
        label->setText(QApplication::translate("image_info", "Contraste:", Q_NULLPTR));
        IMG->setText(QString());
        Basic_box->setTitle(QApplication::translate("image_info", "Informaci\303\263n b\303\241sica", Q_NULLPTR));
        name_label->setText(QApplication::translate("image_info", "Nombre: ", Q_NULLPTR));
        format_label->setText(QApplication::translate("image_info", "Formato imagen: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class image_info: public Ui_image_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_INFO_H
