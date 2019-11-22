/********************************************************************************
** Form generated from reading UI file 'runapp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNAPP_H
#define UI_RUNAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunApp
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *cmdComboBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *cancleBtn;
    QPushButton *viewBtn;

    void setupUi(QWidget *RunApp)
    {
        if (RunApp->objectName().isEmpty())
            RunApp->setObjectName(QStringLiteral("RunApp"));
        RunApp->resize(609, 278);
        verticalLayout_2 = new QVBoxLayout(RunApp);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(RunApp);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 16777215));
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/huxings/Desktop/run.png")));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(RunApp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(RunApp);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label_3);

        cmdComboBox = new QComboBox(RunApp);
        cmdComboBox->setObjectName(QStringLiteral("cmdComboBox"));
        cmdComboBox->setMinimumSize(QSize(0, 40));
        cmdComboBox->setMaximumSize(QSize(16777215, 40));
        cmdComboBox->setEditable(true);

        horizontalLayout_2->addWidget(cmdComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        sureBtn = new QPushButton(RunApp);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));
        sureBtn->setEnabled(false);
        sureBtn->setMinimumSize(QSize(130, 50));
        sureBtn->setCheckable(false);
        sureBtn->setAutoDefault(false);
        sureBtn->setFlat(false);

        horizontalLayout_3->addWidget(sureBtn);

        cancleBtn = new QPushButton(RunApp);
        cancleBtn->setObjectName(QStringLiteral("cancleBtn"));
        cancleBtn->setMinimumSize(QSize(130, 50));

        horizontalLayout_3->addWidget(cancleBtn);

        viewBtn = new QPushButton(RunApp);
        viewBtn->setObjectName(QStringLiteral("viewBtn"));
        viewBtn->setMinimumSize(QSize(130, 50));
        viewBtn->setMaximumSize(QSize(130, 50));

        horizontalLayout_3->addWidget(viewBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RunApp);

        sureBtn->setDefault(false);


        QMetaObject::connectSlotsByName(RunApp);
    } // setupUi

    void retranslateUi(QWidget *RunApp)
    {
        RunApp->setWindowTitle(QApplication::translate("RunApp", "RunApp", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("RunApp", "Windows\345\260\206\346\240\271\346\215\256\344\275\240\346\211\200\350\276\223\345\205\245\347\232\204\345\220\215\347\247\260\357\274\214\344\270\272\344\275\240\346\211\223\345\274\200\347\233\270\345\272\224\347\232\204\347\250\213\345\272\217\343\200\201\346\226\207\344\273\266\345\244\271\343\200\201\346\226\207\346\241\243\346\210\226Internet\350\265\204\346\272\220\343\200\202", 0));
        label_3->setText(QApplication::translate("RunApp", "\346\211\223\345\274\200(O)\357\274\232", 0));
        sureBtn->setText(QApplication::translate("RunApp", "\347\241\256\345\256\232", 0));
        cancleBtn->setText(QApplication::translate("RunApp", "\345\217\226\346\266\210", 0));
        viewBtn->setText(QApplication::translate("RunApp", "\346\265\217\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class RunApp: public Ui_RunApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNAPP_H
