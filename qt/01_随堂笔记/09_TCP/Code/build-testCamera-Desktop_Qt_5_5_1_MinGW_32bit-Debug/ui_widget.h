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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *windowLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *widthSpinBox;
    QLabel *label_2;
    QSpinBox *heightSpinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *photoPushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(840, 983);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        windowLayout = new QGridLayout();
        windowLayout->setSpacing(6);
        windowLayout->setObjectName(QStringLiteral("windowLayout"));

        verticalLayout->addLayout(windowLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(label);

        widthSpinBox = new QSpinBox(Widget);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setMinimumSize(QSize(100, 0));
        widthSpinBox->setMaximumSize(QSize(16777215, 60));
        widthSpinBox->setMaximum(3000);

        horizontalLayout->addWidget(widthSpinBox);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(label_2);

        heightSpinBox = new QSpinBox(Widget);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setMinimumSize(QSize(100, 0));
        heightSpinBox->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(heightSpinBox);

        horizontalSpacer = new QSpacerItem(40, 60, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        photoPushButton = new QPushButton(Widget);
        photoPushButton->setObjectName(QStringLiteral("photoPushButton"));
        photoPushButton->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(photoPushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "\345\256\275\357\274\232", 0));
        label_2->setText(QApplication::translate("Widget", "\351\253\230\357\274\232", 0));
        photoPushButton->setText(QApplication::translate("Widget", "\346\213\215\347\205\247", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
