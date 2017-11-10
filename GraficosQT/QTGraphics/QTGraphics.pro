#-------------------------------------------------
#
# Project created by QtCreator 2017-11-10T17:03:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTGraphics
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


SOURCES += \
        main.cpp \
        dialog.cpp \
    poligononlados.cpp \
    cubo.cpp \
    cono.cpp \
    prismabaserect.cpp \
    prismabasetrian.cpp \
    arco.cpp \
    poligononlados.cpp

HEADERS += \
        dialog.h \
    poligononlados.h \
    cubo.h \
    cono.h \
    prismabaserect.h \
    prismabasetrian.h \
    arco.h \
    poligononlados.h

FORMS += \
        dialog.ui \
    cubo.ui \
    cono.ui \
    prismabaserect.ui \
    prismabasetrian.ui \
    arco.ui \
    poligononlados.ui
