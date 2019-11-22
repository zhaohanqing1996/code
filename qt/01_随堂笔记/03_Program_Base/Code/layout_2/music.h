#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QSpacerItem>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>


class Music : public QWidget
{
    Q_OBJECT

public:
    Music(QWidget *parent = 0);
    ~Music();

private:

    QVBoxLayout * showPartLayout();
    QVBoxLayout * listPartLayout();
    QHBoxLayout * controlPartLayout();
    void mainLayout();

private:
    // 显示部分
    QLabel * titleLabel;            // 标题标签
    QSlider * progressSlider;       // 进度滑条
    QLabel * currentTimeLabel;
    QSpacerItem * timeSpacer;
    QLabel * totalTimeLabel;

    // 列表部分
    QPushButton * scanLocalFileBtn;
    QPushButton * showPlayListBtn;

    // 控制部分
    QComboBox * playModeComboBox;
    QPushButton * preSongBtn;
    QPushButton * playBtn;
    QPushButton * nextSongBtn;
    QSpacerItem * volSpacer;
    QLabel * volLabel;
    QSlider * volSlider;
};

#endif // MUSIC_H
