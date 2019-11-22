/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton_boy;
    QRadioButton *radioButton_lady;
    QRadioButton *radioButton_not;
    QRadioButton *radioButton_ok;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 54, 12));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 110, 54, 12));
        radioButton_boy = new QRadioButton(Widget);
        radioButton_boy->setObjectName(QStringLiteral("radioButton_boy"));
        radioButton_boy->setGeometry(QRect(140, 70, 89, 16));
        radioButton_lady = new QRadioButton(Widget);
        radioButton_lady->setObjectName(QStringLiteral("radioButton_lady"));
        radioButton_lady->setGeometry(QRect(250, 70, 89, 16));
        radioButton_not = new QRadioButton(Widget);
        radioButton_not->setObjectName(QStringLiteral("radioButton_not"));
        radioButton_not->setGeometry(QRect(140, 110, 89, 16));
        radioButton_ok = new QRadioButton(Widget);
        radioButton_ok->setObjectName(QStringLiteral("radioButton_ok"));
        radioButton_ok->setGeometry(QRect(250, 110, 89, 16));
        pushButton_ok = new QPushButton(Widget);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(124, 170, 91, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "\346\200\247\345\210\253\351\200\211\346\213\251", 0));
        label_2->setText(QApplication::translate("Widget", "\345\251\232\345\247\273\347\212\266\345\206\265", 0));
        radioButton_boy->setText(QApplication::translate("Widget", "\347\224\267", 0));
        radioButton_lady->setText(QApplication::translate("Widget", "\345\245\263", 0));
        radioButton_not->setText(QApplication::translate("Widget", "\346\234\252\345\251\232", 0));
        radioButton_ok->setText(QApplication::translate("Widget", "\345\267\262\345\251\232", 0));
        pushButton_ok->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\351\200\211\346\213\251\347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
