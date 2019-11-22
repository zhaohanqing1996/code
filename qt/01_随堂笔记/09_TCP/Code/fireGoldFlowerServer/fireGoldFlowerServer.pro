#-------------------------------------------------
#
# Project created by QtCreator 2017-09-29T14:19:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fireGoldFlowerServer
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    clientthread.cpp

HEADERS  += server.h \
    clientthread.h

FORMS    += server.ui
