#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public:
    void setServer(QTcpSocket *p);

private slots:
    void on_loginBtn_clicked();

    void readMsg();

private:
    Ui::LoginDialog *ui;

    QTcpSocket * server;


};

#endif // LOGINDIALOG_H
