/********************************************************************************
** Form generated from reading UI file 'run.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUN_H
#define UI_RUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Run
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *Run)
    {
        if (Run->objectName().isEmpty())
            Run->setObjectName(QStringLiteral("Run"));
        Run->resize(470, 219);
        label = new QLabel(Run);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 121, 41));
        label_2 = new QLabel(Run);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 130, 121, 41));
        lineEdit = new QLineEdit(Run);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 76, 301, 31));
        lineEdit_2 = new QLineEdit(Run);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 134, 301, 31));

        retranslateUi(Run);

        QMetaObject::connectSlotsByName(Run);
    } // setupUi

    void retranslateUi(QWidget *Run)
    {
        Run->setWindowTitle(QApplication::translate("Run", "Form", 0));
        label->setText(QApplication::translate("Run", "\350\264\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("Run", "\345\257\206\347\240\201\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Run: public Ui_Run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUN_H
