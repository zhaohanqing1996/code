/********************************************************************************
** Form generated from reading UI file 'easynote.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYNOTE_H
#define UI_EASYNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasyNote
{
public:
    QAction *newFileAction;
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *saveFileAsAction;
    QAction *pageSetAction;
    QAction *printAction;
    QAction *quitAciton;
    QAction *action_U_2;
    QAction *action_T;
    QAction *action_C;
    QAction *action_P_2;
    QAction *action_L;
    QAction *action_F;
    QAction *action_N;
    QAction *action_R;
    QAction *action_G;
    QAction *action_A_2;
    QAction *action_D;
    QAction *action_W;
    QAction *action_F_2;
    QAction *action_S_2;
    QAction *action_H;
    QAction *action_A_3;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *contentTextEdit;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_V;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EasyNote)
    {
        if (EasyNote->objectName().isEmpty())
            EasyNote->setObjectName(QStringLiteral("EasyNote"));
        EasyNote->resize(746, 601);
        newFileAction = new QAction(EasyNote);
        newFileAction->setObjectName(QStringLiteral("newFileAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/\346\226\260\345\273\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        newFileAction->setIcon(icon);
        openFileAction = new QAction(EasyNote);
        openFileAction->setObjectName(QStringLiteral("openFileAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/\345\233\276\347\211\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        openFileAction->setIcon(icon1);
        saveFileAction = new QAction(EasyNote);
        saveFileAction->setObjectName(QStringLiteral("saveFileAction"));
        saveFileAsAction = new QAction(EasyNote);
        saveFileAsAction->setObjectName(QStringLiteral("saveFileAsAction"));
        pageSetAction = new QAction(EasyNote);
        pageSetAction->setObjectName(QStringLiteral("pageSetAction"));
        printAction = new QAction(EasyNote);
        printAction->setObjectName(QStringLiteral("printAction"));
        quitAciton = new QAction(EasyNote);
        quitAciton->setObjectName(QStringLiteral("quitAciton"));
        action_U_2 = new QAction(EasyNote);
        action_U_2->setObjectName(QStringLiteral("action_U_2"));
        action_T = new QAction(EasyNote);
        action_T->setObjectName(QStringLiteral("action_T"));
        action_C = new QAction(EasyNote);
        action_C->setObjectName(QStringLiteral("action_C"));
        action_P_2 = new QAction(EasyNote);
        action_P_2->setObjectName(QStringLiteral("action_P_2"));
        action_L = new QAction(EasyNote);
        action_L->setObjectName(QStringLiteral("action_L"));
        action_F = new QAction(EasyNote);
        action_F->setObjectName(QStringLiteral("action_F"));
        action_N = new QAction(EasyNote);
        action_N->setObjectName(QStringLiteral("action_N"));
        action_R = new QAction(EasyNote);
        action_R->setObjectName(QStringLiteral("action_R"));
        action_G = new QAction(EasyNote);
        action_G->setObjectName(QStringLiteral("action_G"));
        action_A_2 = new QAction(EasyNote);
        action_A_2->setObjectName(QStringLiteral("action_A_2"));
        action_D = new QAction(EasyNote);
        action_D->setObjectName(QStringLiteral("action_D"));
        action_W = new QAction(EasyNote);
        action_W->setObjectName(QStringLiteral("action_W"));
        action_F_2 = new QAction(EasyNote);
        action_F_2->setObjectName(QStringLiteral("action_F_2"));
        action_S_2 = new QAction(EasyNote);
        action_S_2->setObjectName(QStringLiteral("action_S_2"));
        action_H = new QAction(EasyNote);
        action_H->setObjectName(QStringLiteral("action_H"));
        action_A_3 = new QAction(EasyNote);
        action_A_3->setObjectName(QStringLiteral("action_A_3"));
        centralWidget = new QWidget(EasyNote);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        contentTextEdit = new QPlainTextEdit(centralWidget);
        contentTextEdit->setObjectName(QStringLiteral("contentTextEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(14);
        contentTextEdit->setFont(font);

        verticalLayout->addWidget(contentTextEdit);

        EasyNote->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EasyNote);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 746, 30));
        fileMenu = new QMenu(menuBar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_O = new QMenu(menuBar);
        menu_O->setObjectName(QStringLiteral("menu_O"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QStringLiteral("menu_V"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        EasyNote->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EasyNote);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EasyNote->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EasyNote);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EasyNote->setStatusBar(statusBar);

        menuBar->addAction(fileMenu->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_O->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_H->menuAction());
        fileMenu->addAction(newFileAction);
        fileMenu->addAction(openFileAction);
        fileMenu->addAction(saveFileAction);
        fileMenu->addAction(saveFileAsAction);
        fileMenu->addSeparator();
        fileMenu->addAction(pageSetAction);
        fileMenu->addAction(printAction);
        fileMenu->addSeparator();
        fileMenu->addAction(quitAciton);
        menu_E->addAction(action_U_2);
        menu_E->addSeparator();
        menu_E->addAction(action_T);
        menu_E->addAction(action_C);
        menu_E->addAction(action_P_2);
        menu_E->addAction(action_L);
        menu_E->addSeparator();
        menu_E->addAction(action_F);
        menu_E->addAction(action_N);
        menu_E->addAction(action_R);
        menu_E->addAction(action_G);
        menu_E->addSeparator();
        menu_E->addAction(action_A_2);
        menu_E->addAction(action_D);
        menu_O->addAction(action_W);
        menu_O->addAction(action_F_2);
        menu_V->addAction(action_S_2);
        menu_H->addAction(action_H);
        menu_H->addSeparator();
        menu_H->addAction(action_A_3);
        mainToolBar->addAction(newFileAction);
        mainToolBar->addAction(openFileAction);

        retranslateUi(EasyNote);

        QMetaObject::connectSlotsByName(EasyNote);
    } // setupUi

    void retranslateUi(QMainWindow *EasyNote)
    {
        EasyNote->setWindowTitle(QApplication::translate("EasyNote", "EasyNote", 0));
        newFileAction->setText(QApplication::translate("EasyNote", "\346\226\260\345\273\272(&N\357\274\211", 0));
#ifndef QT_NO_TOOLTIP
        newFileAction->setToolTip(QApplication::translate("EasyNote", "\345\210\233\345\273\272\344\270\200\344\270\252\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        newFileAction->setShortcut(QApplication::translate("EasyNote", "Ctrl+N", 0));
        openFileAction->setText(QApplication::translate("EasyNote", "\346\211\223\345\274\200(&O)", 0));
        openFileAction->setShortcut(QApplication::translate("EasyNote", "Ctrl+O", 0));
        saveFileAction->setText(QApplication::translate("EasyNote", "\344\277\235\345\255\230(&S)", 0));
        saveFileAction->setShortcut(QApplication::translate("EasyNote", "Ctrl+S", 0));
        saveFileAsAction->setText(QApplication::translate("EasyNote", "\345\217\246\345\255\230\344\270\272(&A)", 0));
        pageSetAction->setText(QApplication::translate("EasyNote", "\351\241\265\351\235\242\350\256\276\347\275\256(&U)", 0));
        printAction->setText(QApplication::translate("EasyNote", "\346\211\223\345\215\260(&P)", 0));
        printAction->setShortcut(QApplication::translate("EasyNote", "Ctrl+P", 0));
        quitAciton->setText(QApplication::translate("EasyNote", "\351\200\200\345\207\272(&X)", 0));
        action_U_2->setText(QApplication::translate("EasyNote", "\346\222\244\351\224\200(&U)", 0));
        action_T->setText(QApplication::translate("EasyNote", "\345\211\252\345\210\207(&T)", 0));
        action_C->setText(QApplication::translate("EasyNote", "\345\244\215\345\210\266(&C)", 0));
        action_P_2->setText(QApplication::translate("EasyNote", "\347\262\230\350\264\264(&P)", 0));
        action_L->setText(QApplication::translate("EasyNote", "\345\210\240\351\231\244(&L)", 0));
        action_F->setText(QApplication::translate("EasyNote", "\346\237\245\346\211\276(&F)", 0));
        action_N->setText(QApplication::translate("EasyNote", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252(&N)", 0));
        action_R->setText(QApplication::translate("EasyNote", "\346\233\277\346\215\242(&R)", 0));
        action_G->setText(QApplication::translate("EasyNote", "\350\275\254\345\210\260(&G)", 0));
        action_A_2->setText(QApplication::translate("EasyNote", "\345\205\250\351\200\211(&A)", 0));
        action_D->setText(QApplication::translate("EasyNote", "\346\227\245\346\234\237/\346\227\266\351\227\264(&D)", 0));
        action_W->setText(QApplication::translate("EasyNote", "\350\207\252\345\212\250\346\215\242\350\241\214(&W)", 0));
        action_F_2->setText(QApplication::translate("EasyNote", "\345\255\227\344\275\223(&F)", 0));
        action_S_2->setText(QApplication::translate("EasyNote", "\347\212\266\346\200\201\346\240\217(&S)", 0));
        action_H->setText(QApplication::translate("EasyNote", "\346\237\245\347\234\213\345\270\256\345\212\251(&H)", 0));
        action_A_3->setText(QApplication::translate("EasyNote", "\345\205\263\344\272\216\350\256\260\344\272\213\346\234\254(&A)", 0));
        fileMenu->setTitle(QApplication::translate("EasyNote", "\346\226\207\344\273\266(&F)", 0));
        menu_E->setTitle(QApplication::translate("EasyNote", "\347\274\226\350\276\221(&E)", 0));
        menu_O->setTitle(QApplication::translate("EasyNote", "\346\240\274\345\274\217(&O)", 0));
        menu_V->setTitle(QApplication::translate("EasyNote", "\346\237\245\347\234\213(&V)", 0));
        menu_H->setTitle(QApplication::translate("EasyNote", "\345\270\256\345\212\251(&H)", 0));
    } // retranslateUi

};

namespace Ui {
    class EasyNote: public Ui_EasyNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYNOTE_H
