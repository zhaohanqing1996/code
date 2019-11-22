/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hello
{
public:
    QLabel *label;

    void setupUi(QWidget *Hello)
    {
        if (Hello->objectName().isEmpty())
            Hello->setObjectName(QStringLiteral("Hello"));
        Hello->resize(707, 281);
        label = new QLabel(Hello);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 60, 391, 141));
        QFont font;
        font.setFamily(QStringLiteral("Baskerville Old Face"));
        font.setPointSize(22);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(6);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Hello);

        QMetaObject::connectSlotsByName(Hello);
    } // setupUi

    void retranslateUi(QWidget *Hello)
    {
        Hello->setWindowTitle(QApplication::translate("Hello", "Hello", 0));
        label->setText(QApplication::translate("Hello", "hello Qt!!!!", 0));
    } // retranslateUi

};

namespace Ui {
    class Hello: public Ui_Hello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
