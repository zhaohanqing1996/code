#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    memberInit();

    connect(menu,SIGNAL(triggered(QAction*)),this,SLOT(flushActionSlot(QAction*)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)   // 鼠标左键按下
    {
        ui->picLabel->setPixmap(QPixmap("C:/Users/huxings/Desktop/3.jpg"));
        qDebug() << "=======鼠标左键按下=======";
    }
    if(e->button() == Qt::RightButton)  // 鼠标右键按下
    {
        menu->move(e->globalX(), e->globalY());
        menu->show();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)   // 鼠标左键松开
    {
        ui->picLabel->setPixmap(QPixmap("C:/Users/huxings/Desktop/2.jpg"));
        qDebug() << "=======鼠标左键松开=======";
    }
}

bool Widget::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        // 1.截获  在这里处理  不分派给 对应的事件处理函数了
        QMouseEvent *mEvent = static_cast<QMouseEvent *>(e);
        if(mEvent->button() == Qt::LeftButton)   // 鼠标左键按下
        {
            ui->picLabel->setPixmap(QPixmap("C:/Users/huxings/Desktop/3.jpg"));
            qDebug() << "event: 鼠标左键按下";
            return true;
        }
        // 2.附加  在这里处理一下，再分派给对应的事件处理函数处理
        if(mEvent->button() == Qt::RightButton)  // 鼠标右键按下
        {
            menu->move(mEvent->globalX(), mEvent->globalY());
            menu->show();
            qDebug() << "event: 鼠标右键按下";
        }
    }
        // 3.过滤屏蔽   事件这里被拦截了，不会再分派给对应的事件处理函数处理
    else if(e->type() == QEvent::KeyPress)
    {
        return true;
    }
    return QWidget::event(e);
}

void Widget::memberInit()
{
    menu = new QMenu(this);
    menu->addAction("查看");
    menu->addAction("排序方式");
    menu->addAction("刷新");
    menu->addSeparator();
    menu->addAction("粘贴");
    menu->addAction("粘贴快捷方式");
    menu->addSeparator();
    menu->addAction("新建");
    menu->addSeparator();
    menu->addAction("显示设置");
    menu->addAction("个性化");

    ui->picLabel->setScaledContents(true);
}

void Widget::flushActionSlot(QAction *s)
{
    if(s->text() == "刷新")
    {
        qDebug() << "刷新了........";
    }
}
