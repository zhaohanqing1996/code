/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *textLabel;
    QLabel *picLabel;
    QLabel *gifLabel;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QSlider *speedSlider;
    QLabel *numLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(956, 754);
        textLabel = new QLabel(Widget);
        textLabel->setObjectName(QStringLiteral("textLabel"));
        textLabel->setGeometry(QRect(20, 20, 891, 51));
        textLabel->setFrameShape(QFrame::Box);
        picLabel = new QLabel(Widget);
        picLabel->setObjectName(QStringLiteral("picLabel"));
        picLabel->setGeometry(QRect(20, 90, 241, 331));
        picLabel->setFrameShape(QFrame::Box);
        gifLabel = new QLabel(Widget);
        gifLabel->setObjectName(QStringLiteral("gifLabel"));
        gifLabel->setGeometry(QRect(500, 90, 381, 401));
        gifLabel->setFrameShape(QFrame::Box);
        playBtn = new QPushButton(Widget);
        playBtn->setObjectName(QStringLiteral("playBtn"));
        playBtn->setGeometry(QRect(500, 530, 141, 51));
        stopBtn = new QPushButton(Widget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setGeometry(QRect(740, 530, 141, 51));
        speedSlider = new QSlider(Widget);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setGeometry(QRect(910, 90, 22, 401));
        speedSlider->setMaximum(400);
        speedSlider->setValue(100);
        speedSlider->setOrientation(Qt::Vertical);
        numLabel = new QLabel(Widget);
        numLabel->setObjectName(QStringLiteral("numLabel"));
        numLabel->setGeometry(QRect(30, 540, 311, 61));
        numLabel->setFrameShape(QFrame::Box);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        textLabel->setText(QString());
        picLabel->setText(QString());
        gifLabel->setText(QString());
        playBtn->setText(QApplication::translate("Widget", "\346\222\255\346\224\276", 0));
        stopBtn->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", 0));
        numLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
