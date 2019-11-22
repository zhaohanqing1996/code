#ifndef EASYMUSIC_H
#define EASYMUSIC_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QUrl>
#include <QMediaPlaylist>
#include <QDebug>
#include <QFileDialog>
#include <QStringList>
#include <QListWidget>

namespace Ui {
class EasyMusic;
}

class EasyMusic : public QWidget
{
    Q_OBJECT

public:
    enum PlayState{Play, Pause};

public:
    explicit EasyMusic(QWidget *parent = 0);
    ~EasyMusic();

public:
    bool isInFileList(QString &name);

    QString timeToString(qint64 t);

public slots:
    void addSongSlot();

    void updateShowList();

    void updateShowListState();
    void updateMediaPlayState();
    void updatePlayBackMode(int n);

    void updateShowListRow(int n);

    void updateRateSliderRange(qint64 dur);
    void updateRateSliderValue(qint64 pos);
    void updatePlayPostion();
    void disconnectSliderPlayer();

    void updateCurrentTime(qint64 pos);

    void updatePlayTip();

    void playMusic();

private:
    Ui::EasyMusic *ui;

    QMediaPlayer * player;          // 播放器对象
    QMediaPlaylist * mediaList;     // 媒体内容列表
    QStringList fileList;           // 文件名称列表
    QListWidget * showList;         // 显示列表

    PlayState mediaState;           // 媒体的状态（播放/暂停）
    bool showListState;             // 显示列表的状态(显示/隐藏)
                                    // true 显示   false 隐藏

};

#endif // EASYMUSIC_H
