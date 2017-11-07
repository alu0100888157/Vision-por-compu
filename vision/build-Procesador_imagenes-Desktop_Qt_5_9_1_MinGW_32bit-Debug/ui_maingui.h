/********************************************************************************
** Form generated from reading UI file 'maingui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGUI_H
#define UI_MAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGui
{
public:
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionGuardar_como;
    QAction *actionSalir;
    QAction *actionInformaci_n;
    QAction *actionSobre;
    QAction *actionSobre_Qt;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuarchivo;
    QMenu *menuEditar;
    QMenu *menuImagen;
    QMenu *menuAyuda;
    QMenu *menuV_deo;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainGui)
    {
        if (MainGui->objectName().isEmpty())
            MainGui->setObjectName(QStringLiteral("MainGui"));
        MainGui->resize(400, 71);
        MainGui->setMaximumSize(QSize(16777215, 71000));
        actionAbrir = new QAction(MainGui);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionGuardar = new QAction(MainGui);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionGuardar_como = new QAction(MainGui);
        actionGuardar_como->setObjectName(QStringLiteral("actionGuardar_como"));
        actionSalir = new QAction(MainGui);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionInformaci_n = new QAction(MainGui);
        actionInformaci_n->setObjectName(QStringLiteral("actionInformaci_n"));
        actionSobre = new QAction(MainGui);
        actionSobre->setObjectName(QStringLiteral("actionSobre"));
        actionSobre_Qt = new QAction(MainGui);
        actionSobre_Qt->setObjectName(QStringLiteral("actionSobre_Qt"));
        centralWidget = new QWidget(MainGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 7));
        MainGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuarchivo = new QMenu(menuBar);
        menuarchivo->setObjectName(QStringLiteral("menuarchivo"));
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        menuImagen = new QMenu(menuBar);
        menuImagen->setObjectName(QStringLiteral("menuImagen"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuAyuda->sizePolicy().hasHeightForWidth());
        menuAyuda->setSizePolicy(sizePolicy);
        menuAyuda->setMaximumSize(QSize(16000, 16000));
        menuV_deo = new QMenu(menuBar);
        menuV_deo->setObjectName(QStringLiteral("menuV_deo"));
        MainGui->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainGui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainGui->setStatusBar(statusBar);
        toolBar = new QToolBar(MainGui);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainGui->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuarchivo->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuBar->addAction(menuImagen->menuAction());
        menuBar->addAction(menuV_deo->menuAction());
        menuBar->addAction(menuAyuda->menuAction());

        retranslateUi(MainGui);

        QMetaObject::connectSlotsByName(MainGui);
    } // setupUi

    void retranslateUi(QMainWindow *MainGui)
    {
        MainGui->setWindowTitle(QApplication::translate("MainGui", "Procesador de Im\303\241genes", Q_NULLPTR));
        actionAbrir->setText(QApplication::translate("MainGui", "Abrir...", Q_NULLPTR));
        actionGuardar->setText(QApplication::translate("MainGui", "Guardar", Q_NULLPTR));
        actionGuardar_como->setText(QApplication::translate("MainGui", "Guardar como...", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("MainGui", "Salir", Q_NULLPTR));
        actionInformaci_n->setText(QApplication::translate("MainGui", "Informaci\303\263n", Q_NULLPTR));
        actionSobre->setText(QApplication::translate("MainGui", "Sobre ", Q_NULLPTR));
        actionSobre_Qt->setText(QApplication::translate("MainGui", "Sobre Qt", Q_NULLPTR));
        menuarchivo->setTitle(QApplication::translate("MainGui", "Archivo", Q_NULLPTR));
        menuEditar->setTitle(QApplication::translate("MainGui", "Editar", Q_NULLPTR));
        menuImagen->setTitle(QApplication::translate("MainGui", "Imagen", Q_NULLPTR));
        menuAyuda->setTitle(QApplication::translate("MainGui", "Ayuda", Q_NULLPTR));
        menuV_deo->setTitle(QApplication::translate("MainGui", "V\303\255deo", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainGui", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainGui: public Ui_MainGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGUI_H
