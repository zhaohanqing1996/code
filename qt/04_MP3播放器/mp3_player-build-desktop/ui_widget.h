/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Mon Aug 11 00:21:04 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetClass
{
public:
    QLabel *label;
    QPushButton *btn_open;
    QPushButton *btn_perv;
    QPushButton *btn_play;
    QPushButton *btn_stop;
    QPushButton *btn_next;
    QSlider *process_bar;
    QSlider *voice_bar;
    QPushButton *btn_voice;
    QPushButton *btn_pause;

    void setupUi(QWidget *WidgetClass)
    {
        if (WidgetClass->objectName().isEmpty())
            WidgetClass->setObjectName(QString::fromUtf8("WidgetClass"));
        WidgetClass->resize(320, 220);
        label = new QLabel(WidgetClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 321, 221));
        label->setPixmap(QPixmap(QString::fromUtf8(":/mp3_src/apple_logo.bmp")));
        btn_open = new QPushButton(WidgetClass);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));
        btn_open->setGeometry(QRect(40, 160, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/mp3_src/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_open->setIcon(icon);
        btn_open->setIconSize(QSize(24, 24));
        btn_open->setFlat(true);
        btn_perv = new QPushButton(WidgetClass);
        btn_perv->setObjectName(QString::fromUtf8("btn_perv"));
        btn_perv->setGeometry(QRect(80, 160, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/mp3_src/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_perv->setIcon(icon1);
        btn_perv->setIconSize(QSize(24, 24));
        btn_perv->setFlat(true);
        btn_play = new QPushButton(WidgetClass);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));
        btn_play->setGeometry(QRect(120, 160, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/mp3_src/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon2);
        btn_play->setIconSize(QSize(24, 24));
        btn_play->setFlat(true);
        btn_stop = new QPushButton(WidgetClass);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(200, 160, 31, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/mp3_src/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_stop->setIcon(icon3);
        btn_stop->setIconSize(QSize(24, 24));
        btn_stop->setFlat(true);
        btn_next = new QPushButton(WidgetClass);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setGeometry(QRect(240, 160, 31, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/mp3_src/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon4);
        btn_next->setIconSize(QSize(24, 24));
        btn_next->setFlat(true);
        process_bar = new QSlider(WidgetClass);
        process_bar->setObjectName(QString::fromUtf8("process_bar"));
        process_bar->setGeometry(QRect(30, 200, 261, 5));
        process_bar->setOrientation(Qt::Horizontal);
        voice_bar = new QSlider(WidgetClass);
        voice_bar->setObjectName(QString::fromUtf8("voice_bar"));
        voice_bar->setGeometry(QRect(270, 30, 8, 101));
        voice_bar->setMaximum(100);
        voice_bar->setValue(100);
        voice_bar->setOrientation(Qt::Vertical);
        btn_voice = new QPushButton(WidgetClass);
        btn_voice->setObjectName(QString::fromUtf8("btn_voice"));
        btn_voice->setGeometry(QRect(260, 130, 31, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/mp3_src/voice.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        btn_voice->setIcon(icon5);
        btn_voice->setIconSize(QSize(24, 24));
        btn_voice->setFlat(true);
        btn_pause = new QPushButton(WidgetClass);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));
        btn_pause->setGeometry(QRect(160, 160, 31, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/mp3_src/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause->setIcon(icon6);
        btn_pause->setIconSize(QSize(24, 24));
        btn_pause->setFlat(true);

        retranslateUi(WidgetClass);

        QMetaObject::connectSlotsByName(WidgetClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetClass)
    {
        WidgetClass->setWindowTitle(QApplication::translate("WidgetClass", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        btn_open->setText(QString());
        btn_perv->setText(QString());
        btn_play->setText(QString());
        btn_stop->setText(QString());
        btn_next->setText(QString());
        btn_voice->setText(QString());
        btn_pause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetClass: public Ui_WidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
