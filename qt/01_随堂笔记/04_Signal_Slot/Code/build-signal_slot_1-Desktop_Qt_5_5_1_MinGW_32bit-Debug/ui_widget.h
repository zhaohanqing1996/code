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
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *clearBtn;
    QLineEdit *inputLineEdit;
    QFontComboBox *fontComboBox;
    QLabel *textLabel;
    QSpinBox *spinBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(813, 607);
        clearBtn = new QPushButton(Widget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));
        clearBtn->setGeometry(QRect(80, 180, 531, 61));
        inputLineEdit = new QLineEdit(Widget);
        inputLineEdit->setObjectName(QStringLiteral("inputLineEdit"));
        inputLineEdit->setGeometry(QRect(70, 60, 551, 81));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(80, 290, 541, 51));
        textLabel = new QLabel(Widget);
        textLabel->setObjectName(QStringLiteral("textLabel"));
        textLabel->setGeometry(QRect(90, 390, 511, 61));
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(630, 290, 71, 51));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 450, 581, 41));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 520, 581, 41));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 450, 112, 34));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(650, 520, 112, 34));

        retranslateUi(Widget);
        QObject::connect(clearBtn, SIGNAL(clicked()), inputLineEdit, SLOT(clear()));
        QObject::connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), Widget, SLOT(setLabelFontFamily(QFont)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), Widget, SLOT(setLabelPointSize(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit, SLOT(copy()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), lineEdit_2, SLOT(paste()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        clearBtn->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", 0));
        textLabel->setText(QApplication::translate("Widget", "Hello QT!!!", 0));
        pushButton->setText(QApplication::translate("Widget", "\345\244\215\345\210\266", 0));
        pushButton_2->setText(QApplication::translate("Widget", "\347\262\230\350\264\264", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
