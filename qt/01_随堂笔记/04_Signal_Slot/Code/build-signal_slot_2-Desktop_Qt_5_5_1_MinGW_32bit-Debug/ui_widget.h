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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QDoubleSpinBox *radiusDoubleSpinBox;
    QLabel *label_2;
    QLabel *areaLabel;
    QPushButton *calculateBtn;
    QPushButton *clearBtn;
    QFontComboBox *fontComboBox;
    QPushButton *clearContentBtn;
    QPushButton *clearAllBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(431, 556);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 100, 81, 61));
        radiusDoubleSpinBox = new QDoubleSpinBox(Widget);
        radiusDoubleSpinBox->setObjectName(QStringLiteral("radiusDoubleSpinBox"));
        radiusDoubleSpinBox->setGeometry(QRect(120, 110, 271, 41));
        radiusDoubleSpinBox->setMaximum(1.23132e+15);
        radiusDoubleSpinBox->setValue(3.98);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 170, 71, 41));
        areaLabel = new QLabel(Widget);
        areaLabel->setObjectName(QStringLiteral("areaLabel"));
        areaLabel->setGeometry(QRect(120, 170, 271, 51));
        areaLabel->setFrameShape(QFrame::Box);
        calculateBtn = new QPushButton(Widget);
        calculateBtn->setObjectName(QStringLiteral("calculateBtn"));
        calculateBtn->setGeometry(QRect(40, 240, 351, 51));
        clearBtn = new QPushButton(Widget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));
        clearBtn->setGeometry(QRect(40, 320, 351, 51));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(40, 400, 361, 41));
        clearContentBtn = new QPushButton(Widget);
        clearContentBtn->setObjectName(QStringLiteral("clearContentBtn"));
        clearContentBtn->setGeometry(QRect(40, 470, 351, 51));
        clearAllBtn = new QPushButton(Widget);
        clearAllBtn->setObjectName(QStringLiteral("clearAllBtn"));
        clearAllBtn->setGeometry(QRect(50, 30, 351, 61));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "\345\215\212\345\276\204\357\274\232", 0));
        label_2->setText(QApplication::translate("Widget", "\351\235\242\347\247\257\357\274\232", 0));
        areaLabel->setText(QString());
        calculateBtn->setText(QApplication::translate("Widget", "\350\256\241\347\256\227", 0));
        clearBtn->setText(QApplication::translate("Widget", "\345\275\222\351\233\266", 0));
        clearContentBtn->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\347\273\223\346\236\234", 0));
        clearAllBtn->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
