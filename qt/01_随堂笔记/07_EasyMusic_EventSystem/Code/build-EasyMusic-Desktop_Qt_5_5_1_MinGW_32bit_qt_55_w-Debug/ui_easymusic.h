/********************************************************************************
** Form generated from reading UI file 'easymusic.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYMUSIC_H
#define UI_EASYMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasyMusic
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QSlider *playRateSlider;
    QHBoxLayout *horizontalLayout;
    QLabel *currentTimeLabel;
    QSpacerItem *timeSpacer;
    QLabel *totalTimeLabel;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addSongBtn;
    QPushButton *showHideListBtn;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *playModeComboBox;
    QPushButton *preSongBtn;
    QPushButton *playPauseBtn;
    QPushButton *nextSongBtn;
    QSpacerItem *volumeSpacer;
    QLabel *volumeLabel;
    QSlider *volumeSlider;

    void setupUi(QWidget *EasyMusic)
    {
        if (EasyMusic->objectName().isEmpty())
            EasyMusic->setObjectName(QStringLiteral("EasyMusic"));
        EasyMusic->resize(641, 176);
        EasyMusic->setStyleSheet(QStringLiteral("EasyMusic{background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.0858369 rgba(0, 255, 138, 69), stop:0.167382 rgba(195, 255, 0, 240), stop:0.477581 rgba(0, 255, 138, 130), stop:0.518717 rgba(0, 255, 138, 130), stop:0.55 rgba(0, 255, 138, 255), stop:0.625 rgba(255, 255, 0, 69), stop:0.742489 rgba(247, 255, 0, 208), stop:0.841202 rgba(255, 203, 0, 130), stop:1 rgba(255, 255, 0, 69));}"));
        verticalLayout_4 = new QVBoxLayout(EasyMusic);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleLabel = new QLabel(EasyMusic);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        verticalLayout->addWidget(titleLabel);

        playRateSlider = new QSlider(EasyMusic);
        playRateSlider->setObjectName(QStringLiteral("playRateSlider"));
        playRateSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(playRateSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        currentTimeLabel = new QLabel(EasyMusic);
        currentTimeLabel->setObjectName(QStringLiteral("currentTimeLabel"));

        horizontalLayout->addWidget(currentTimeLabel);

        timeSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(timeSpacer);

        totalTimeLabel = new QLabel(EasyMusic);
        totalTimeLabel->setObjectName(QStringLiteral("totalTimeLabel"));

        horizontalLayout->addWidget(totalTimeLabel);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addSongBtn = new QPushButton(EasyMusic);
        addSongBtn->setObjectName(QStringLiteral("addSongBtn"));

        verticalLayout_2->addWidget(addSongBtn);

        showHideListBtn = new QPushButton(EasyMusic);
        showHideListBtn->setObjectName(QStringLiteral("showHideListBtn"));

        verticalLayout_2->addWidget(showHideListBtn);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        playModeComboBox = new QComboBox(EasyMusic);
        playModeComboBox->setObjectName(QStringLiteral("playModeComboBox"));

        horizontalLayout_3->addWidget(playModeComboBox);

        preSongBtn = new QPushButton(EasyMusic);
        preSongBtn->setObjectName(QStringLiteral("preSongBtn"));

        horizontalLayout_3->addWidget(preSongBtn);

        playPauseBtn = new QPushButton(EasyMusic);
        playPauseBtn->setObjectName(QStringLiteral("playPauseBtn"));

        horizontalLayout_3->addWidget(playPauseBtn);

        nextSongBtn = new QPushButton(EasyMusic);
        nextSongBtn->setObjectName(QStringLiteral("nextSongBtn"));

        horizontalLayout_3->addWidget(nextSongBtn);

        volumeSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(volumeSpacer);

        volumeLabel = new QLabel(EasyMusic);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));

        horizontalLayout_3->addWidget(volumeLabel);

        volumeSlider = new QSlider(EasyMusic);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(50);
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(volumeSlider);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(EasyMusic);

        QMetaObject::connectSlotsByName(EasyMusic);
    } // setupUi

    void retranslateUi(QWidget *EasyMusic)
    {
        EasyMusic->setWindowTitle(QApplication::translate("EasyMusic", "EasyMusic", 0));
        titleLabel->setText(QApplication::translate("EasyMusic", "\346\227\240\346\255\214\346\233\262\357\274\232", 0));
        currentTimeLabel->setText(QApplication::translate("EasyMusic", "00:00", 0));
        totalTimeLabel->setText(QApplication::translate("EasyMusic", "00:00", 0));
        addSongBtn->setText(QApplication::translate("EasyMusic", "\346\267\273\345\212\240\346\255\214\346\233\262", 0));
        showHideListBtn->setText(QApplication::translate("EasyMusic", "\346\230\276\347\244\272\345\210\227\350\241\250", 0));
        playModeComboBox->clear();
        playModeComboBox->insertItems(0, QStringList()
         << QApplication::translate("EasyMusic", "\351\241\272\345\272\217\345\210\227\350\241\250", 0)
         << QApplication::translate("EasyMusic", "\345\210\227\350\241\250\345\276\252\347\216\257", 0)
         << QApplication::translate("EasyMusic", "\345\215\225\346\233\262\344\270\200\346\254\241", 0)
         << QApplication::translate("EasyMusic", "\345\215\225\346\233\262\345\276\252\347\216\257", 0)
         << QApplication::translate("EasyMusic", "\351\232\217\346\234\272\346\222\255\346\224\276", 0)
        );
        preSongBtn->setText(QApplication::translate("EasyMusic", "\344\270\212\344\270\200\351\246\226", 0));
        playPauseBtn->setText(QApplication::translate("EasyMusic", "\346\222\255\346\224\276", 0));
        nextSongBtn->setText(QApplication::translate("EasyMusic", "\344\270\213\344\270\200\351\246\226", 0));
        volumeLabel->setText(QApplication::translate("EasyMusic", "\351\237\263\351\207\217", 0));
    } // retranslateUi

};

namespace Ui {
    class EasyMusic: public Ui_EasyMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYMUSIC_H
