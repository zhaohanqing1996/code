#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QObject *
    // QPushButton *
    connect(ui->clearBtn, SIGNAL(clicked(bool)),this,SLOT(clearInput()));
    connect(ui->fontComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(clearInput()));

    connect(ui->clearContentBtn,SIGNAL(clicked(bool)),ui->areaLabel,SLOT(clear()));

    connect(ui->clearAllBtn,SIGNAL(clicked(bool)),ui->radiusDoubleSpinBox,SLOT(clear()));
    connect(ui->clearAllBtn,SIGNAL(clicked(bool)),ui->areaLabel,SLOT(clear()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_calculateBtn_clicked()
{
    double r = ui->radiusDoubleSpinBox->value();
    double area = 3.1415926 * r * r;

    QString s;
    s.setNum(area);
    ui->areaLabel->setText(s);
    // double --> QString
}

void Widget::clearInput()
{
    qDebug() << "clear Input running....";
    ui->radiusDoubleSpinBox->setValue(0);
    ui->areaLabel->setText("0");
}
