#-------------------------------------------------
#
# Project created by QtCreator 2017-11-25T09:44:32
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpClient
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp

HEADERS  += client.h

FORMS    += client.ui
