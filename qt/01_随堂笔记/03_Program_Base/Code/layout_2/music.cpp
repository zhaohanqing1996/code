#include "music.h"

Music::Music(QWidget *parent)
    : QWidget(parent)
{
    mainLayout();

}

Music::~Music()
{

}

QVBoxLayout *Music::showPartLayout()
{
    titleLabel = new QLabel("无歌曲：");
    progressSlider = new QSlider(Qt::Horizontal);       // 进度滑条
    currentTimeLabel = new QLabel("00:00");
    timeSpacer = new QSpacerItem(400, 20, QSizePolicy::Expanding);
    totalTimeLabel = new QLabel("00:00");

    QHBoxLayout *timeLayout = new QHBoxLayout;
    timeLayout->addWidget(currentTimeLabel);
    timeLayout->addSpacerItem(timeSpacer);
    timeLayout->addWidget(totalTimeLabel);

    QVBoxLayout *showLayout = new QVBoxLayout;
    showLayout->addWidget(titleLabel);
    showLayout->addWidget(progressSlider);
    showLayout->addLayout(timeLayout);

    return showLayout;
}

QVBoxLayout *Music::listPartLayout()
{
    scanLocalFileBtn = new QPushButton("扫描本地文件");
    showPlayListBtn = new QPushButton("显示播放列表");
    QVBoxLayout * listLayout = new QVBoxLayout;
    listLayout->addWidget(scanLocalFileBtn);
    listLayout->addWidget(showPlayListBtn);

    return listLayout;
}

QHBoxLayout *Music::controlPartLayout()
{
    playModeComboBox = new QComboBox;
    playModeComboBox->addItem("顺序播放");
    playModeComboBox->addItem("顺序列表");
    playModeComboBox->addItem("单曲一次");
    playModeComboBox->addItem("单曲循环");
    playModeComboBox->addItem("随机播放");

    preSongBtn = new QPushButton("上一首");
    playBtn = new QPushButton("播放");;
    nextSongBtn = new QPushButton("下一首");

    volSpacer = new QSpacerItem(200, 20,QSizePolicy::Expanding);
    volLabel = new QLabel("音量");
    volSlider = new QSlider(Qt::Horizontal);

    QHBoxLayout * controlLayout = new QHBoxLayout;
    controlLayout->addWidget(playModeComboBox);
    controlLayout->addWidget(preSongBtn);
    controlLayout->addWidget(playBtn);
    controlLayout->addWidget(nextSongBtn);
    controlLayout->addSpacerItem(volSpacer);
    controlLayout->addWidget(volLabel);
    controlLayout->addWidget(volSlider);

    return controlLayout;
}

void Music::mainLayout()
{
    QHBoxLayout * topLayout = new QHBoxLayout;
    topLayout->addLayout(showPartLayout());
    topLayout->addLayout(listPartLayout());

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addLayout(topLayout);
    layout->addLayout(controlPartLayout());

    this->setLayout(layout);
}
