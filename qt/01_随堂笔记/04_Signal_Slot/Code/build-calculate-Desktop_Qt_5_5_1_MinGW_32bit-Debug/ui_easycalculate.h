/********************************************************************************
** Form generated from reading UI file 'easycalculate.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYCALCULATE_H
#define UI_EASYCALCULATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasyCalculate
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *showLineEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearAllBtn;
    QPushButton *clearOneBtn;
    QPushButton *divBtn;
    QPushButton *mulBtn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *subBtn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *addBtn;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn0;
    QPushButton *btn_point;
    QPushButton *equalBtn;

    void setupUi(QWidget *EasyCalculate)
    {
        if (EasyCalculate->objectName().isEmpty())
            EasyCalculate->setObjectName(QStringLiteral("EasyCalculate"));
        EasyCalculate->resize(304, 452);
        verticalLayout_4 = new QVBoxLayout(EasyCalculate);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        showLineEdit = new QLineEdit(EasyCalculate);
        showLineEdit->setObjectName(QStringLiteral("showLineEdit"));
        showLineEdit->setMinimumSize(QSize(0, 60));
        showLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        showLineEdit->setReadOnly(true);

        verticalLayout_3->addWidget(showLineEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        clearAllBtn = new QPushButton(EasyCalculate);
        clearAllBtn->setObjectName(QStringLiteral("clearAllBtn"));
        clearAllBtn->setMinimumSize(QSize(60, 60));
        clearAllBtn->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(clearAllBtn);

        clearOneBtn = new QPushButton(EasyCalculate);
        clearOneBtn->setObjectName(QStringLiteral("clearOneBtn"));
        clearOneBtn->setMinimumSize(QSize(60, 60));
        clearOneBtn->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(clearOneBtn);

        divBtn = new QPushButton(EasyCalculate);
        divBtn->setObjectName(QStringLiteral("divBtn"));
        divBtn->setMinimumSize(QSize(60, 60));
        divBtn->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(divBtn);

        mulBtn = new QPushButton(EasyCalculate);
        mulBtn->setObjectName(QStringLiteral("mulBtn"));
        mulBtn->setMinimumSize(QSize(60, 60));
        mulBtn->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(mulBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn1 = new QPushButton(EasyCalculate);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setMinimumSize(QSize(60, 60));
        btn1->setMaximumSize(QSize(60, 60));

        horizontalLayout_2->addWidget(btn1);

        btn2 = new QPushButton(EasyCalculate);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setMinimumSize(QSize(60, 60));
        btn2->setMaximumSize(QSize(60, 60));

        horizontalLayout_2->addWidget(btn2);

        btn3 = new QPushButton(EasyCalculate);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setMinimumSize(QSize(60, 60));
        btn3->setMaximumSize(QSize(60, 60));

        horizontalLayout_2->addWidget(btn3);

        subBtn = new QPushButton(EasyCalculate);
        subBtn->setObjectName(QStringLiteral("subBtn"));
        subBtn->setMinimumSize(QSize(60, 60));
        subBtn->setMaximumSize(QSize(60, 60));

        horizontalLayout_2->addWidget(subBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn4 = new QPushButton(EasyCalculate);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setMinimumSize(QSize(60, 60));
        btn4->setMaximumSize(QSize(60, 60));

        horizontalLayout_3->addWidget(btn4);

        btn5 = new QPushButton(EasyCalculate);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setMinimumSize(QSize(60, 60));
        btn5->setMaximumSize(QSize(60, 60));

        horizontalLayout_3->addWidget(btn5);

        btn6 = new QPushButton(EasyCalculate);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setMinimumSize(QSize(60, 60));
        btn6->setMaximumSize(QSize(60, 60));

        horizontalLayout_3->addWidget(btn6);

        addBtn = new QPushButton(EasyCalculate);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setMinimumSize(QSize(60, 60));
        addBtn->setMaximumSize(QSize(60, 60));

        horizontalLayout_3->addWidget(addBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btn7 = new QPushButton(EasyCalculate);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setMinimumSize(QSize(60, 60));
        btn7->setMaximumSize(QSize(60, 60));

        horizontalLayout_4->addWidget(btn7);

        btn8 = new QPushButton(EasyCalculate);
        btn8->setObjectName(QStringLiteral("btn8"));
        btn8->setMinimumSize(QSize(60, 60));
        btn8->setMaximumSize(QSize(60, 60));

        horizontalLayout_4->addWidget(btn8);

        btn9 = new QPushButton(EasyCalculate);
        btn9->setObjectName(QStringLiteral("btn9"));
        btn9->setMinimumSize(QSize(60, 60));
        btn9->setMaximumSize(QSize(60, 60));

        horizontalLayout_4->addWidget(btn9);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btn0 = new QPushButton(EasyCalculate);
        btn0->setObjectName(QStringLiteral("btn0"));
        btn0->setMinimumSize(QSize(130, 60));
        btn0->setMaximumSize(QSize(130, 60));

        horizontalLayout_5->addWidget(btn0);

        btn_point = new QPushButton(EasyCalculate);
        btn_point->setObjectName(QStringLiteral("btn_point"));
        btn_point->setMinimumSize(QSize(60, 60));
        btn_point->setMaximumSize(QSize(60, 60));

        horizontalLayout_5->addWidget(btn_point);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);

        equalBtn = new QPushButton(EasyCalculate);
        equalBtn->setObjectName(QStringLiteral("equalBtn"));
        equalBtn->setMinimumSize(QSize(60, 130));
        equalBtn->setMaximumSize(QSize(60, 130));

        horizontalLayout_6->addWidget(equalBtn);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(EasyCalculate);

        QMetaObject::connectSlotsByName(EasyCalculate);
    } // setupUi

    void retranslateUi(QWidget *EasyCalculate)
    {
        EasyCalculate->setWindowTitle(QApplication::translate("EasyCalculate", "EasyCalculate", 0));
        showLineEdit->setPlaceholderText(QApplication::translate("EasyCalculate", "0", 0));
        clearAllBtn->setText(QApplication::translate("EasyCalculate", "C", 0));
        clearOneBtn->setText(QApplication::translate("EasyCalculate", "<-", 0));
        divBtn->setText(QApplication::translate("EasyCalculate", "/", 0));
        mulBtn->setText(QApplication::translate("EasyCalculate", "*", 0));
        btn1->setText(QApplication::translate("EasyCalculate", "1", 0));
        btn2->setText(QApplication::translate("EasyCalculate", "2", 0));
        btn3->setText(QApplication::translate("EasyCalculate", "3", 0));
        subBtn->setText(QApplication::translate("EasyCalculate", "-", 0));
        btn4->setText(QApplication::translate("EasyCalculate", "4", 0));
        btn5->setText(QApplication::translate("EasyCalculate", "5", 0));
        btn6->setText(QApplication::translate("EasyCalculate", "6", 0));
        addBtn->setText(QApplication::translate("EasyCalculate", "+", 0));
        btn7->setText(QApplication::translate("EasyCalculate", "7", 0));
        btn8->setText(QApplication::translate("EasyCalculate", "8", 0));
        btn9->setText(QApplication::translate("EasyCalculate", "9", 0));
        btn0->setText(QApplication::translate("EasyCalculate", "0", 0));
        btn_point->setText(QApplication::translate("EasyCalculate", ".", 0));
        equalBtn->setText(QApplication::translate("EasyCalculate", "=", 0));
    } // retranslateUi

};

namespace Ui {
    class EasyCalculate: public Ui_EasyCalculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYCALCULATE_H
