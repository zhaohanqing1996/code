/********************************************************************************
** Form generated from reading UI file 'easypic.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYPIC_H
#define UI_EASYPIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasyPic
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *localFileBtn;
    QPushButton *preBtn;
    QPushButton *nextBtn;
    QPushButton *addBtn;
    QPushButton *deleteBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *showLabel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *EasyPic)
    {
        if (EasyPic->objectName().isEmpty())
            EasyPic->setObjectName(QStringLiteral("EasyPic"));
        EasyPic->resize(721, 362);
        verticalLayout_3 = new QVBoxLayout(EasyPic);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        localFileBtn = new QPushButton(EasyPic);
        localFileBtn->setObjectName(QStringLiteral("localFileBtn"));
        localFileBtn->setMinimumSize(QSize(130, 40));
        localFileBtn->setMaximumSize(QSize(130, 40));

        verticalLayout->addWidget(localFileBtn);

        preBtn = new QPushButton(EasyPic);
        preBtn->setObjectName(QStringLiteral("preBtn"));
        preBtn->setMinimumSize(QSize(130, 40));
        preBtn->setMaximumSize(QSize(130, 40));

        verticalLayout->addWidget(preBtn);

        nextBtn = new QPushButton(EasyPic);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setMinimumSize(QSize(130, 40));
        nextBtn->setMaximumSize(QSize(130, 40));

        verticalLayout->addWidget(nextBtn);

        addBtn = new QPushButton(EasyPic);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setMinimumSize(QSize(130, 40));
        addBtn->setMaximumSize(QSize(130, 40));

        verticalLayout->addWidget(addBtn);

        deleteBtn = new QPushButton(EasyPic);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setMinimumSize(QSize(130, 40));
        deleteBtn->setMaximumSize(QSize(130, 40));

        verticalLayout->addWidget(deleteBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        showLabel = new QLabel(EasyPic);
        showLabel->setObjectName(QStringLiteral("showLabel"));
        showLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(showLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(EasyPic);

        QMetaObject::connectSlotsByName(EasyPic);
    } // setupUi

    void retranslateUi(QWidget *EasyPic)
    {
        EasyPic->setWindowTitle(QApplication::translate("EasyPic", "EasyPic", 0));
        localFileBtn->setText(QApplication::translate("EasyPic", "\346\234\254\345\234\260\346\226\207\344\273\266", 0));
        preBtn->setText(QApplication::translate("EasyPic", "\344\270\212\344\270\200\345\274\240", 0));
        nextBtn->setText(QApplication::translate("EasyPic", "\344\270\213\344\270\200\345\274\240", 0));
        addBtn->setText(QApplication::translate("EasyPic", "\346\267\273\345\212\240", 0));
        deleteBtn->setText(QApplication::translate("EasyPic", "\345\210\240\351\231\244", 0));
        showLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EasyPic: public Ui_EasyPic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYPIC_H
