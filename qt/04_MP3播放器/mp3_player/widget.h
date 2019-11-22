#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QStringList>
#include <QFileDialog>
#include <string.h>
#include <QMessageBox>
#include <QTimer>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <linux/soundcard.h>

namespace Ui
{
    class WidgetClass;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::WidgetClass *ui;
    QTimer *timer;


private slots:
    void on_btn_pause_clicked();
    void on_voice_bar_valueChanged(int value);
    void on_btn_voice_clicked();
    void on_btn_next_clicked();
    void on_btn_perv_clicked();
    void on_btn_stop_clicked();
    void on_btn_play_clicked();
    void on_btn_open_clicked();

    void process_move();
    void mp3_play();
};

#endif // WIDGET_H
