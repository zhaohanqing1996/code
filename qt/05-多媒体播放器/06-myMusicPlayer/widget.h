#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <phonon>
#include "lrcwindow.h"
#include "musiclist.h"
#include <QTimer>
#include <QSystemTrayIcon>
#include <QMenu>

#include <QTextEdit>
class QLabel;
namespace Ui
{
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void creatActions();

    void setCurrentLrc();

protected:
    void changeEvent(QEvent *e);
    void wheelEvent(QWheelEvent *);
    bool eventFilter(QObject *, QEvent *);
    void contextMenuEvent(QContextMenuEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);
    void closeEvent(QCloseEvent *);

    void moveEvent(QMoveEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
private:
    Ui::Widget *ui;
    musicList *mList;
    Phonon::MediaObject *audio;
    Phonon::MediaObject *musicInformationMediaObject;
    Phonon::VideoWidget *videoWidget;
    Phonon::AudioOutput *audioOutput;
    Phonon::SeekSlider *seekSlider;
    Phonon::VolumeSlider *volumeSlider;
    QList<Phonon::MediaSource> musicSourceList;

    QWidget *lrcWidget;
    QLabel *lrcLabel;

    lrcWindow *lrc;
    lrcWindow *lrc2;

    QTimer *timer;

    QIcon *iconplay;
    QIcon *iconpause;

    QAction *play;
    QAction *stop;
    QAction *open;
    QAction *sound;
    QAction *exit;

    QAction *remove;

    QSystemTrayIcon *trayicon;
    QMenu *trayiconMenu;

    void readSettings();
    void writeSettings();


    QTextEdit *text;

    bool isTouched;

private slots:
    void on_toolButton_List_clicked(bool checked);
    void tableWidget_cellDoubleClicked(int row, int column);
    void on_toolButton_lrcD_clicked(bool checked);
    void on_toolButton_next_clicked();
    void on_toolButton_stop_clicked();
    void on_toolButton_playpause_clicked();
    void on_toolButton_previous_clicked();
    void on_toolButton_open_clicked();
    void showTime(qint64);

    void Timeout();

    void musicInformationStateChanged(Phonon::State,Phonon::State);
    void mediaObjectStateChanged(Phonon::State,Phonon::State);
    void musicAboutToFinish();
    void currentMusicSourceChanged(Phonon::MediaSource);

    void removeSlot();
    void exitSlot();

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

signals:
    void mySignal();

};

#endif // WIDGET_H
