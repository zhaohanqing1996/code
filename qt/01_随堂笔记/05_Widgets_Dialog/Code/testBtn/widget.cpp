#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1.创建一个菜单
    QMenu * menu = new QMenu;
    menu->addAction("打印");
    menu->addAction("测试谎言");
    menu->addAction(QIcon("C:/Users/huxings/Desktop/512.ico"), "游戏");
    menu->addSeparator();
    menu->addAction("退出");

    // 2.将菜单给指定的按钮
    ui->menuBtn->setMenu(menu);
}

Widget::~Widget()
{
    delete ui;
}
