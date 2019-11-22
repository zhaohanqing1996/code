#include "widget.h"
#include "ui_widget.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    foreach( const QSerialPortInfo &Info,QSerialPortInfo::availablePorts())//读取串口信息
    {
        qDebug() << "portName    :"  << Info.portName();//调试时可以看的串口信息
        qDebug() << "Description   :" << Info.description();
        qDebug() << "Manufacturer:" << Info.manufacturer();
        QSerialPort serial;
        serial.setPort(Info);
        if( serial.open( QIODevice::ReadWrite) )//如果串口是可以读写方式打开的
        {
            ui->comboBox_portName->addItem( Info.portName() );//在comboBox那添加串口号
            serial.close();//然后自动关闭等待人为开启（通过那个打开串口的PushButton）
        }
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_comopen_clicked()
{
    //对串口进行一些初始化
    my_serialPort = new QSerialPort(this);
    my_serialPort->setPortName( ui->comboBox_portName->currentText() );
    my_serialPort->open( QIODevice::ReadWrite );
    qDebug() << ui->comboBox_portName->currentText();
    my_serialPort->setBaudRate(  ui->comboBox_baudRate->currentText().toInt() );//波特率
    my_serialPort->setDataBits( QSerialPort::Data8 );//数据字节，8字节
    my_serialPort->setParity( QSerialPort::NoParity );//校验，无
    my_serialPort->setFlowControl( QSerialPort::NoFlowControl );//数据流控制,无
    my_serialPort->setStopBits( QSerialPort::OneStop );//一位停止位
    timer = new QTimer(this);
    connect( timer, SIGNAL( timeout() ), this, SLOT( readMyCom() ) );
    timer->start(1000);//每秒读一次
}

void Widget::on_pushButton_send_clicked()
{
    my_serialPort->write( ui->lineEdit_write->text().toUtf8() );
}
void Widget::readMyCom()//读取缓冲的数据，每秒读一次
{
    requestData = my_serialPort->readAll();//用requestData存储从串口那读取的数据
    if(requestData!=NULL)//如果读取到有数据，就显示出来。
    {
        ui->textEdit_read->append(requestData);
    }
    requestData.clear();    //清除缓冲区
}


