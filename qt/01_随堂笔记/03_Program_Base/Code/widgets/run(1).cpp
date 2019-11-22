#include "run.h"
#include "ui_run.h"

Run::Run(QWidget *parent, Qt::WindowFlags f) :
    QWidget(parent, f),
    ui(new Ui::Run)
{
    ui->setupUi(this);
}

Run::~Run()
{
    delete ui;
}
