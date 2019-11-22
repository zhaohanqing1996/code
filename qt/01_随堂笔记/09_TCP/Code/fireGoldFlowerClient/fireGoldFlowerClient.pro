#-------------------------------------------------
#
# Project created by QtCreator 2017-09-29T15:28:32
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fireGoldFlowerClient
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    logindialog.cpp

HEADERS  += client.h \
    logindialog.h

FORMS    += client.ui \
    logindialog.ui
