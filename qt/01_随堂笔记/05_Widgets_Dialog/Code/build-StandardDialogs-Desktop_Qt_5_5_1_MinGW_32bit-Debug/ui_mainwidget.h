/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *colorBtn;
    QPushButton *fileBtn;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(672, 454);
        colorBtn = new QPushButton(MainWidget);
        colorBtn->setObjectName(QStringLiteral("colorBtn"));
        colorBtn->setGeometry(QRect(70, 100, 231, 41));
        fileBtn = new QPushButton(MainWidget);
        fileBtn->setObjectName(QStringLiteral("fileBtn"));
        fileBtn->setGeometry(QRect(70, 180, 231, 41));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0));
        colorBtn->setText(QApplication::translate("MainWidget", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206", 0));
        fileBtn->setText(QApplication::translate("MainWidget", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
