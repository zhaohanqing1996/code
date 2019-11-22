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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_comopen;
    QTextEdit *textEdit_read;
    QLineEdit *lineEdit_write;
    QComboBox *comboBox_portName;
    QComboBox *comboBox_baudRate;
    QPushButton *pushButton_send;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 51, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 100, 51, 21));
        pushButton_comopen = new QPushButton(Widget);
        pushButton_comopen->setObjectName(QStringLiteral("pushButton_comopen"));
        pushButton_comopen->setGeometry(QRect(30, 220, 91, 31));
        pushButton_comopen->setStyleSheet(QStringLiteral(""));
        textEdit_read = new QTextEdit(Widget);
        textEdit_read->setObjectName(QStringLiteral("textEdit_read"));
        textEdit_read->setGeometry(QRect(203, 50, 131, 91));
        lineEdit_write = new QLineEdit(Widget);
        lineEdit_write->setObjectName(QStringLiteral("lineEdit_write"));
        lineEdit_write->setGeometry(QRect(202, 160, 131, 31));
        comboBox_portName = new QComboBox(Widget);
        comboBox_portName->setObjectName(QStringLiteral("comboBox_portName"));
        comboBox_portName->setGeometry(QRect(100, 60, 69, 22));
        comboBox_baudRate = new QComboBox(Widget);
        comboBox_baudRate->setObjectName(QStringLiteral("comboBox_baudRate"));
        comboBox_baudRate->setGeometry(QRect(100, 100, 69, 22));
        pushButton_send = new QPushButton(Widget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(240, 210, 91, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p>\344\270\262\345\217\243\345\217\267\357\274\232</p></body></html>", 0));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p>\346\263\242\347\211\271\347\216\207\357\274\232</p></body></html>", 0));
        pushButton_comopen->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        comboBox_baudRate->clear();
        comboBox_baudRate->insertItems(0, QStringList()
         << QApplication::translate("Widget", "4800", 0)
         << QApplication::translate("Widget", "9600", 0)
         << QApplication::translate("Widget", "115200", 0)
        );
        pushButton_send->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
