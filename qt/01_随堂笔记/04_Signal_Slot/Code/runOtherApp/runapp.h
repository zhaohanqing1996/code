#ifndef RUNAPP_H
#define RUNAPP_H

#include <QWidget>
#include <QProcess>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class RunApp;
}

class RunApp : public QWidget
{
    Q_OBJECT

public:
    explicit RunApp(QWidget *parent = 0);
    ~RunApp();

public slots:
    void updateBtnState(QString str);

    void runOtherApp();

private:
    Ui::RunApp *ui;
};

#endif // RUNAPP_H
