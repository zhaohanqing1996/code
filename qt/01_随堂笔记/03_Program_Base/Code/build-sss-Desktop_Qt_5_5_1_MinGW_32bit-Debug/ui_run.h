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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Run
{
public:

    void setupUi(QWidget *Run)
    {
        if (Run->objectName().isEmpty())
            Run->setObjectName(QStringLiteral("Run"));
        Run->resize(680, 300);

        retranslateUi(Run);

        QMetaObject::connectSlotsByName(Run);
    } // setupUi

    void retranslateUi(QWidget *Run)
    {
        Run->setWindowTitle(QApplication::translate("Run", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class Run: public Ui_Run {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUN_H
