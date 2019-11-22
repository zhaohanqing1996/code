/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *addressLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *connectBtn;
    QProgressBar *rateProgressBar;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(627, 418);
        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 80, 111, 61));
        label_2 = new QLabel(Client);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 164, 111, 61));
        addressLineEdit = new QLineEdit(Client);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));
        addressLineEdit->setGeometry(QRect(140, 80, 391, 51));
        portLineEdit = new QLineEdit(Client);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(140, 170, 391, 51));
        connectBtn = new QPushButton(Client);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setGeometry(QRect(410, 250, 121, 34));
        rateProgressBar = new QProgressBar(Client);
        rateProgressBar->setObjectName(QStringLiteral("rateProgressBar"));
        rateProgressBar->setGeometry(QRect(50, 310, 521, 61));
        rateProgressBar->setValue(0);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        label->setText(QApplication::translate("Client", "\344\270\273\346\234\272\357\274\232", 0));
        label_2->setText(QApplication::translate("Client", "\347\253\257\345\217\243\357\274\232", 0));
        connectBtn->setText(QApplication::translate("Client", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
