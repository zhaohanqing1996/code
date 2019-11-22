#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_button = new QPushButton("按钮松开状态",this);
    m_button->setGeometry(QRect(150, 70, 111, 41));//设置按钮大小/位置
    QObject::connect(m_button,SIGNAL(pressed()),this,SLOT(QPushButton_pressed_Slots()));
    QObject::connect(m_button,SIGNAL(released()),this,SLOT(QPushButton_released_Slots()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::QPushButton_pressed_Slots()
{
    m_button->setText(tr("按钮按下状态"));
}
void Widget::QPushButton_released_Slots()
{
    m_button->setText(tr("按钮松开状态"));
}

