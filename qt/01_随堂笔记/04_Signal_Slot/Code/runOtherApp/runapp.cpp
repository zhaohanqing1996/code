#include "runapp.h"
#include "ui_runapp.h"

RunApp::RunApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunApp)
{
    ui->setupUi(this);

    connect(ui->cmdComboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(updateBtnState(QString)));
    connect(ui->sureBtn,SIGNAL(clicked(bool)),this,SLOT(runOtherApp()));
    connect(ui->cmdComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(runOtherApp()));
}

RunApp::~RunApp()
{
    delete ui;
}

void RunApp::updateBtnState(QString str)
{
    qDebug() << "str: " << str;
    if(str.isEmpty())
    {
        ui->sureBtn->setEnabled(false);
    }
    else if(!ui->sureBtn->isEnabled())
    {
        ui->sureBtn->setEnabled(true);
    }
}

void RunApp::runOtherApp()
{
    qDebug() << "正在启动一个新的进程";
    QString cmd = ui->cmdComboBox->currentText();
    QProcess * newApp = new QProcess(this);

    newApp->start(cmd);
}


