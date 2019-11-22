#-------------------------------------------------
#
# Project created by QtCreator 2017-11-25T09:26:55
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpServer
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp

HEADERS  += server.h

FORMS    += server.ui
