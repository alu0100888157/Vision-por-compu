#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T03:37:06
#
#-------------------------------------------------

QT       += core gui printsupport multimedia multimediawidgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Procesador_imagenes
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = icono.ico

SOURCES += \
        main.cpp \
        maingui.cpp \
    image_viewer.cpp \
    image_info.cpp \
    image_selector_gray.cpp \
    image_selector_rgb.cpp \
    camara_selector.cpp \
    image_histogram.cpp \
    trans_lineal.cpp \
    brightness_and_contrast.cpp

HEADERS += \
        maingui.h \
    image_viewer.h \
    image_info.h \
    image_selector_gray.h \
    image_selector_rgb.h \
    camara_selector.h \
    image_histogram.h \
    trans_lineal.h \
    brightness_and_contrast.h

FORMS += \
        maingui.ui \
    image_info.ui \
    image_selector_gray.ui \
    image_selector_rgb.ui \
    camara_selector.ui \
    image_histogram.ui \
    trans_lineal.ui \
    brightness_and_contrast.ui

RESOURCES += \
    application.qrc

DISTFILES +=
