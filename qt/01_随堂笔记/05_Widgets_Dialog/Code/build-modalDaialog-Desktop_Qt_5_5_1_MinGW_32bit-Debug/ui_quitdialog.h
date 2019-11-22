/********************************************************************************
** Form generated from reading UI file 'quitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUITDIALOG_H
#define UI_QUITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_quitDialog
{
public:
    QLabel *label;
    QPushButton *quitBtn;
    QPushButton *stayBtn;

    void setupUi(QDialog *quitDialog)
    {
        if (quitDialog->objectName().isEmpty())
            quitDialog->setObjectName(QStringLiteral("quitDialog"));
        quitDialog->resize(415, 161);
        label = new QLabel(quitDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 371, 71));
        quitBtn = new QPushButton(quitDialog);
        quitBtn->setObjectName(QStringLiteral("quitBtn"));
        quitBtn->setGeometry(QRect(110, 100, 112, 34));
        stayBtn = new QPushButton(quitDialog);
        stayBtn->setObjectName(QStringLiteral("stayBtn"));
        stayBtn->setGeometry(QRect(280, 100, 112, 34));

        retranslateUi(quitDialog);

        QMetaObject::connectSlotsByName(quitDialog);
    } // setupUi

    void retranslateUi(QDialog *quitDialog)
    {
        quitDialog->setWindowTitle(QApplication::translate("quitDialog", "Dialog", 0));
        label->setText(QApplication::translate("quitDialog", "\344\275\240\347\234\237\347\232\204\350\246\201\345\277\215\345\277\203\351\200\200\345\207\272\345\220\227\357\274\237\357\274\237\357\274\237\357\274\237", 0));
        quitBtn->setText(QApplication::translate("quitDialog", "\345\277\215\345\277\203\351\200\200\345\207\272", 0));
        stayBtn->setText(QApplication::translate("quitDialog", "\345\247\224\345\251\211\347\225\231\344\270\213", 0));
    } // retranslateUi

};

namespace Ui {
    class quitDialog: public Ui_quitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUITDIALOG_H
