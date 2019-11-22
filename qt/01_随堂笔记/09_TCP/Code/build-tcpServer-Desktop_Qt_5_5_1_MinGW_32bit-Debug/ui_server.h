/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QLabel *label;
    QPushButton *sendFileBtn;
    QProgressBar *rateProgressBar;

    void setupUi(QDialog *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(586, 336);
        label = new QLabel(Server);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 481, 101));
        label->setFrameShape(QFrame::Box);
        sendFileBtn = new QPushButton(Server);
        sendFileBtn->setObjectName(QStringLiteral("sendFileBtn"));
        sendFileBtn->setGeometry(QRect(40, 140, 481, 51));
        rateProgressBar = new QProgressBar(Server);
        rateProgressBar->setObjectName(QStringLiteral("rateProgressBar"));
        rateProgressBar->setGeometry(QRect(40, 230, 521, 51));
        rateProgressBar->setMaximum(100);
        rateProgressBar->setValue(0);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QDialog *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", 0));
        label->setText(QApplication::translate("Server", "\347\255\211\345\276\205\350\277\236\346\216\245...........", 0));
        sendFileBtn->setText(QApplication::translate("Server", "\345\217\221\351\200\201\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
