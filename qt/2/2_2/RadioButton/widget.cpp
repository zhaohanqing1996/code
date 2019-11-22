#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*性别选择组*/
    gender_Group = new QButtonGroup(this);          //新建分组
    gender_Group->addButton(ui->radioButton_boy,0);   //添加按钮，设置ID
    gender_Group->addButton(ui->radioButton_lady,1);

    /*婚姻状况选择组*/
    marriage_Group= new QButtonGroup(this);          //新建分组
    marriage_Group->addButton(ui->radioButton_not,0);  //添加按钮，设置ID
    marriage_Group->addButton(ui->radioButton_ok,1);

    /*关联三个分组的信号和槽*/
    connect(gender_Group, SIGNAL(buttonClicked(int)), this, SLOT(gender_Group_slots(int)));
    connect(marriage_Group, SIGNAL(buttonClicked(int)), this, SLOT(marriage_Group_slots(int)));

}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_ok_clicked()
{
       QString str;//存放显示的结果
       int genderID = gender_Group->checkedId();
       int marriageID = marriage_Group->checkedId();
       /*根据按下的ID区分按键*/
       switch(genderID)
       {
           case 0:
               str+="性别:男\n";
               break;
           case 1:
               str+="性别:女\n";
               break;
       }
       /*根据按下的ID区分按键*/
       switch(marriageID)
       {
           case 0:
               str+="婚姻状况:未婚\n";
               break;
           case 1:
               str+="婚姻状况:已婚\n";
               break;
       }
       /*弹出消息框*/
       QMessageBox::information(this, tr("选择结果"),str,QMessageBox::Ok);
}

//性别选择
void Widget::gender_Group_slots(int id)
{
    QString str;
    /*根据按下的ID区分按键*/
    switch(id)
    {
        case 0:
            str+="性别:男";
            break;
        case 1:
            str+="性别:女";
            break;
    }

    /*弹出消息框*/
    QMessageBox::information(this, tr("选择结果"),str,QMessageBox::Ok);
}

//分组选择
void Widget::marriage_Group_slots(int id)
{
    QString str;
    /*根据按下的ID区分按键*/
    switch(id)
    {
        case 0:
            str+="婚姻状况:未婚";
            break;
        case 1:
            str+="婚姻状况:已婚";
            break;
    }
    /*弹出消息框*/
    QMessageBox::information(this, tr("选择结果"),str,QMessageBox::Ok);
}

