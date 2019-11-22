#include "widget.h"
#include "ui_widget.h"
#include "lrcwindow.h"
#include "musiclist.h"
#include "ui_musiclist.h"
#include <QtGlobal>

#include <QtGui>
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    mList = new musicList(this);
    mList->setFixedSize(300,320);//固定播放列表的大小
    mList->ui->tableWidget->setColumnWidth(0,150);//设置第0列的宽度
    mList->ui->tableWidget->setColumnWidth(1,150);//设置第1列的宽度
    connect(mList->ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),SLOT(tableWidget_cellDoubleClicked(int,int)));
    //mList->show();
    connect(mList,SIGNAL(listClose()),ui->toolButton_List,SLOT(toggle()));

    text = new QTextEdit(this);
    text->hide();   //隐藏 用于查找下句歌词以计算时间间隔
    ui->textEdit->setVisible(false);//文本编辑框不可见，（解析歌词）
    this->setAcceptDrops(true);
    this->setFixedSize(300,150);
    this->setWindowTitle(tr("音乐播放器"));
    readSettings();                 //读取上次关闭窗口时窗口的位置

    QPalette palette = ui->label_lrc->palette();//设置窗体内歌词颜色
    palette.setColor(QPalette::WindowText,Qt::darkBlue);
    ui->label_lrc->setPalette(palette);

    lrc = new lrcWindow(0);//桌面歌词
  //  lrc->show();

    /**初始化媒体**/
    audio =new Phonon::MediaObject();//媒体对象
    audio->setTickInterval(1);//这个属性包含两个节拍之间的时间间隔以毫秒为单位
    audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory);//音频输出
    Phonon::createPath(audio,audioOutput);//连接媒体对象与音频输出

    musicInformationMediaObject = new Phonon::MediaObject(this);  //音乐信息对象

    volumeSlider = new Phonon::VolumeSlider(audioOutput,this);  //音量滑动条
    volumeSlider->move(190,80);
    volumeSlider->resize(50,20);
    volumeSlider->setStyleSheet("background-color:rgb(255,255,255,100)");
    volumeSlider->setFixedWidth(100);//固定音量条大小

    seekSlider = new Phonon::SeekSlider(audio,this); //进度滑动条
    seekSlider->move(10,35);
    seekSlider->resize(170,20);
    seekSlider->setStyleSheet("background-color:rgb(255,255,255,100)");

    connect(audio,SIGNAL(tick(qint64)),this,SLOT(showTime(qint64)));//时间显示与歌词的更新
    connect(audio,SIGNAL(stateChanged(Phonon::State,Phonon::State)),this,SLOT(mediaObjectStateChanged(Phonon::State,Phonon::State)));
    connect(musicInformationMediaObject,SIGNAL(stateChanged(Phonon::State,Phonon::State)),this, SLOT(musicInformationStateChanged(Phonon::State,Phonon::State)));
    //当加入新音乐时执行
    connect(audio,SIGNAL(aboutToFinish()),this,SLOT(musicAboutToFinish()));
    connect(audio,SIGNAL(currentSourceChanged(Phonon::MediaSource)),this,SLOT(currentMusicSourceChanged(Phonon::MediaSource)));

    connect(lrc->exit,SIGNAL(triggered(bool)),ui->toolButton_lrcD,SLOT(setChecked(bool)));

    timer = new QTimer(this);//定时器，若0.1秒不显示歌词，则显示“Music ...”
    timer->start(100);
    connect(timer,SIGNAL(timeout()),SLOT(Timeout()));

    creatActions();
    mList->installEventFilter(this);                //安装事件过滤器
    mList->ui->tableWidget->installEventFilter(this);//事件过滤器
    connect(audioOutput,SIGNAL(mutedChanged(bool)),sound,SLOT(setChecked(bool)));
    connect(this,SIGNAL(mySignal()),this,SLOT(close()),Qt::QueuedConnection);
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        case QEvent::WindowStateChange:
            if (isMinimized())
             {
                 emit mySignal();
                 e->ignore();
             }
        default:
            break;
    }   
}

void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
  QPoint temp = e->pos();
  const int pos_min_x = this->pos().x();
  const int pos_max_x = pos_min_x + this->width();
  const int pos_min_y = this->pos().y();
  const int pos_max_y = pos_min_y + this->height();
  if (temp.x()>pos_min_x && temp.x()<pos_max_x && temp.y()>pos_min_y && temp.y()<pos_max_y )
  {

      //只对标题栏范围内的鼠标事件进行处理
      this->close();
  }
}

void Widget::moveEvent(QMoveEvent *e)
{    
    if(isTouched)
    {
        QPoint p = e->pos() - e->oldPos();
        mList->move(mList->pos() + p);
    }
    else
    {
        isTouched = false;
        if(qAbs(mList->y()- this->y() - this->frameGeometry().height()) < 20)
        {
            isTouched = true;
            this->move(this->x(),mList->y()+this->frameGeometry().height());
        }
        if(qAbs(this->x() - mList->x() - mList->frameGeometry().width()) < 20)
        {
            isTouched = true;
            this->move(mList->x()+mList->frameGeometry().width(),this->y());
        }
        if(qAbs(this->x() + this->frameGeometry().width() - mList->x()) < 20)
        {
            isTouched = true;
            this->move(mList->x()-this->frameGeometry().width(),this->y());
        }      
    }
    QWidget::moveEvent(e);
}

void Widget::readSettings()//读取主窗口的位置信息
{
    QSettings settings("yafeilinux", "Phonon Example");
    QPoint pos = settings.value("pos", QPoint(400,200)).toPoint();
    //QSize size = settings.value("size", QSize(298,412)).toSize();
    move(pos);
    //resize(size);
}

void Widget::writeSettings()//记录主窗口的位置信息
{
    QSettings settings("yafeilinux","Phonon Example");
    settings.setValue("pos", pos());
    //settings.setValue("size", size());
}

void Widget::closeEvent(QCloseEvent *e)//关闭事件
{
    writeSettings();
    mList->listWriteSettings();
    if(this->isVisible())
    {
        this->hide();
        mList->hide();
        trayicon->showMessage(tr("音乐播放器"),tr("最小化到系统托盘，要关闭请右击此图标选择“退出”。"),QSystemTrayIcon::Information,15000);
        e->ignore();
    }
}

bool Widget::eventFilter(QObject *object, QEvent *event)
{qDebug() << object;
    if(object == mList->ui->tableWidget)//过滤表格的事件
    {qDebug() << "event" << event;
        if(event->type() == QEvent::ContextMenu)
        {
            QContextMenuEvent *contextevent = static_cast<QContextMenuEvent *>(event);
            QMenu menu(this);
            menu.addAction(remove);
            menu.exec(contextevent->globalPos());
            return true;
        }
        else if(event->type() == QEvent::DragEnter)
        {
            QDragEnterEvent *dragEnterevent = static_cast<QDragEnterEvent *>(event);
            if(dragEnterevent->mimeData()->hasFormat("text/uri-list"))
                    dragEnterevent->acceptProposedAction();
            return true;
        }
        else if(event->type() == QEvent::Drop)
        {
            QDropEvent *dropevent = static_cast<QDropEvent *>(event);
            dropEvent(dropevent);
            return true;
        }      
        else return false;
    }

    return QWidget::eventFilter(object,event);
}

void Widget::removeSlot()//清空列表
{
    audio->stop();
    int j = mList->ui->tableWidget->rowCount();
    for(int i= 0; i< j; i++)
    {
        mList->ui->tableWidget->removeRow(0);
    }
    mList->ui->tableWidget->close();
    mList->ui->tableWidget->show();
    audio->clear();
    musicSourceList.clear();
}

void Widget::wheelEvent(QWheelEvent *wheelevent)//滚轮事件
{
    if(wheelevent->delta() > 0 )//上滚
    {
       qreal newvolume = audioOutput->volume() + (qreal)0.05;
        if(newvolume >= (qreal)1)
            newvolume = (qreal)1;
        audioOutput->setVolume(newvolume);
    }
    else//下滚
    {
        qreal newvolume = audioOutput->volume() - (qreal)0.05;
        if(newvolume <= (qreal)0)
            newvolume = (qreal)0;
        audioOutput->setVolume(newvolume);
    }
}

void Widget::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu(this);
    menu.addAction(play);
    menu.addAction(stop);
    menu.addAction(open);
    menu.addSeparator();
    menu.addAction(sound);
    menu.addSeparator();
    menu.addAction(exit);
    menu.exec(e->globalPos());
}

void Widget::setCurrentLrc()//设置当前歌词显示
{
    QString fileName = audio->currentSource().fileName();

    QString lrcName = fileName.remove(fileName.right(3)) + "lrc";
    QFile file(lrcName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        ui->label_lrc->setText(tr("当前目录下未找到歌词文件"));
        lrc->setText(tr("当前目录下未找到歌词文件"));
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
}

void Widget::Timeout()//若0.1秒不显示歌词，则显示“请添加音乐”
{
    if(lrc->text().isEmpty())
    {
        lrc->setText(tr("请添加音乐"));
        ui->label_lrc->setText(tr("请添加音乐"));
    }
}
void Widget::showTime(qint64 time)//时间与歌词的更新显示
{
    qint64 temp = audio->totalTime();
    QTime totalTime(0,(temp / 60000) % 60,(temp / 1000) % 60,time %1000);
    QTime curTime(0,(time / 60000) % 60,(time / 1000) % 60,time %1000);
        ui->label_time->setText(tr("%1 / %2")
                       .arg(curTime.toString("mm:ss"))
                       .arg(totalTime.toString("mm:ss")));
    ui->label_time->update();
    /**歌词的更新显示**/

    if(ui->textEdit->find(curTime.toString("mm:ss.zzz").left(7)))//向后找
    {
        QString str = ui->textEdit->textCursor().block().text().replace(QRegExp("\\[\\d{2}:\\d{2}\\.\\d{2}\\]"),"");

        ui->label_lrc->setText(str);
        lrc->setText(str);
        lrc->setLrcWidth();//设置用于遮罩label的宽度为0
     //   lrc->show();

////////////////////////////////////////////////
        QTime tt = curTime;   
        int b = 1;
        int c= 0;
        text->setText(ui->textEdit->document()->toPlainText());
        bool over = ui->textEdit->textCursor().block().next().text().isEmpty();
        while(!over &&!text->find(tt.addMSecs(b*100).toString("mm:ss.zzz").left(7)))
        {
            b++;
            c++;
        }
        while(over && !text->find(tt.addMSecs(b*100).toString("mm:ss.zzz").left(7),QTextDocument::FindBackward))
        {
            b++;
            c++;
            break;
        }

       lrc->timer->start(c);

    }//找不到后向前找
    else if(ui->textEdit->find(curTime.toString("mm:ss.zzz").left(7),QTextDocument::FindBackward))
    {
        QString str = ui->textEdit->textCursor().block().text().replace(QRegExp("\\[\\d{2}:\\d{2}\\.\\d{2}\\]"),"");
        ui->label_lrc->setText(str);
        lrc->setText(str);
        lrc->setLrcWidth();//设置用于遮罩label的宽度为0

       // lrc->show();

////////////////////////////////////////////////
        QTime tt = curTime;   
        int b = 1;
        int c= 0;
        text->setText(ui->textEdit->document()->toPlainText());

        bool over = ui->textEdit->textCursor().block().next().text().isEmpty();
        while(!over && !text->find(tt.addMSecs(b*100).toString("mm:ss.zzz").left(7)))
        {
            b++;
            c++;
        }
        while(over && !text->find(tt.addMSecs(b*100).toString("mm:ss.zzz").left(7),QTextDocument::FindBackward))
        {
            b++;
            c++;
            break;
        }  
         lrc->timer->start(c);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::creatActions()
{
    QIcon iconremove(":/images/remove.png");
    QIcon iconstop(":/images/gtk-media-stop.png");
    QIcon iconopen(":/images/gtk-open.png");
    QIcon iconsound(":/images/sound.png");
    QIcon iconexit(":/images/exit.png");
    iconpause = new QIcon(":/images/gtk-media-pause.png");
    iconplay = new QIcon(":/images/gtk-media-play-ltr.png");

    remove = new QAction(iconremove,tr("清空播放列表"),this);
    connect(remove,SIGNAL(triggered()),this,SLOT(removeSlot()));

    play = new QAction(*iconplay,tr("播放"),this);
    connect(play,SIGNAL(triggered()),this,SLOT(on_toolButton_playpause_clicked()));

    stop = new QAction(iconstop,tr("停止"),this);
    connect(stop,SIGNAL(triggered()),audio,SLOT(stop()));

    open = new QAction(iconopen,tr("打开文件"),this);
    connect(open,SIGNAL(triggered()),this,SLOT(on_toolButton_open_clicked()));

    sound = new QAction(iconsound,tr("静音"),this);
    sound->setCheckable(true);
    connect(sound,SIGNAL(triggered(bool)),audioOutput,SLOT(setMuted(bool)));

    exit = new QAction(iconexit,tr("退出"),this);
    connect(exit,SIGNAL(triggered()),this,SLOT(exitSlot()));

    /***系统托盘****/
    trayicon = new QSystemTrayIcon(this);  //系统托盘
    QIcon ico(":/images/VMP2.png");
    trayiconMenu = new QMenu(this);
    trayiconMenu->addAction(play);
    trayiconMenu->addAction(stop);
    trayiconMenu->addAction(open);
    trayiconMenu->addSeparator();
    trayiconMenu->addAction(exit);

    trayicon->setIcon(ico);
    trayicon->setToolTip(tr("正在播放："));
    trayicon->setContextMenu(trayiconMenu);  //把设置的菜单添加到系统托盘

    trayicon->show();
    trayicon->showMessage(tr("音乐播放器"),tr("欢迎访问：www.yafeilinux.com"),QSystemTrayIcon::Information,10000);

    connect(trayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));//图标被激活时

}

void Widget::exitSlot()//托盘菜单的关闭
{
    this->hide();
    this->close();
}

void Widget::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::Trigger://单击
        case QSystemTrayIcon::DoubleClick://双击
          //  this->readSettings();
            this->setWindowState(Qt::WindowActive);//恢复窗口显示
            this->show();
            if(ui->toolButton_List->isChecked())
            {
                mList->show();
         //       mList->listReadSettings();
            }
            break;
        default:
        ;
    }
}

void Widget::on_toolButton_open_clicked()//打开
{
    QStringList list = QFileDialog::getOpenFileNames(this,tr("打开音乐文件"), QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    if(list.isEmpty()) return;
    int index = musicSourceList.size();  //获取当前列表的长度
    foreach(QString string,list)         //foreach关键字可以循环访问list里面的内容，复制给string
    {
        Phonon::MediaSource source(string);
        musicSourceList.append(source);//在当前列表后加入一条记录
    }
    if(!musicSourceList.isEmpty())
        musicInformationMediaObject->setCurrentSource(musicSourceList.at(index));
    //将新加入的第一条记录添加到musicInformationMediaObject
}

void Widget::on_toolButton_previous_clicked()//上一首
{
    int index = musicSourceList.indexOf(audio->currentSource()) - 1;
    if(index >= 0)
    {
        audio->stop();
        audio->setCurrentSource(musicSourceList.at(index));
        audio->play();
    }

}
void Widget::on_toolButton_playpause_clicked()//播放/暂停
{
    if(audio->state() == Phonon::PlayingState)  audio->pause();
    else
    {
        audio->play();
    }

}

void Widget::on_toolButton_stop_clicked()//停止
{
    audio->stop();
}

void Widget::on_toolButton_next_clicked()//下一首
{
    int index = musicSourceList.indexOf(audio->currentSource()) + 1;
    if(index < musicSourceList.size())
    {
        audio->stop();
        audio->setCurrentSource(musicSourceList.at(index));
        audio->play();
    }
}

void Widget::on_toolButton_lrcD_clicked(bool checked)//显示桌面歌词
{
    if(checked)
    {
        lrc->show();
    }
    else
        lrc->hide();
}

void Widget::musicInformationStateChanged(Phonon::State newState,Phonon::State)
{
    if (newState != Phonon::StoppedState && newState != Phonon::PausedState) return;  //必须加入这句，不然歌曲列表中可能出现重复歌曲
    /************
    刚开始，媒体对象会进入Phonon::LoadingState状态，此时后端进行资源的载入。
    当Phonon::LoadingState完成后就会进入Phonon::StoppedState 状态，
    这时才能添加新的资源。
    ************/
    if (musicInformationMediaObject->currentSource().type() == Phonon::MediaSource::Invalid)return;

    QMap<QString, QString> metaData = musicInformationMediaObject->metaData();

    int rowNum = mList->ui->tableWidget->rowCount();
    mList->ui->tableWidget->insertRow(rowNum);//插入一行

    QString title = metaData.value("TITLE");  //歌曲名称
    if (title == "")
    {
        QString fileName = musicInformationMediaObject->currentSource().fileName();
        QString mp3Name = fileName.right(fileName.length() - fileName.lastIndexOf('/') - 1);
        title = mp3Name;
    }
     QTableWidgetItem *titleItem = new QTableWidgetItem(title);
     mList->ui->tableWidget->setItem(rowNum,0,titleItem);

     QTableWidgetItem *artistItem = new QTableWidgetItem(metaData.value("ARTIST")); //歌手
     mList->ui->tableWidget->setItem(rowNum,1,artistItem);

     qint64 tTime = musicInformationMediaObject->remainingTime();
     QTime tolTime(0,(tTime / 60000) % 60,(tTime / 1000) % 60);
     QString time = tolTime.toString("mm:ss");

     QTableWidgetItem *totalTime = new QTableWidgetItem(time); //专辑
     mList->ui->tableWidget->setItem(rowNum,2,totalTime);

     mList->ui->tableWidget->close();//列表可能显示不全
     mList->ui->tableWidget->show();

     if (mList->ui->tableWidget->selectedItems().isEmpty())
     { //如果没有选择行
         mList->ui->tableWidget->selectRow(0);   //选择第一行
         audio->setCurrentSource(musicInformationMediaObject->currentSource());
     }
     int index = musicSourceList.indexOf(musicInformationMediaObject->currentSource()) + 1;
     if (musicSourceList.size() > index) //如果还未处理完
     {
         musicInformationMediaObject->setCurrentSource(musicSourceList.at(index));
     }  //处理下一首歌曲

     if(audio->state() != Phonon::PlayingState)//打开后播放
     {
         audio->play();
     }

}

void Widget::mediaObjectStateChanged(Phonon::State, Phonon::State)
{
    switch(audio->state())
    {
    case Phonon::PlayingState:
        {
            lrc->setText("Music ...");
            ui->label_lrc->setText("Music ...");
            setCurrentLrc();//打开歌词文件
            play->setIcon(*iconpause);
            ui->toolButton_playpause->setIcon(*iconpause);
            ui->toolButton_playpause->setToolTip(tr("暂停"));
            play->setText(tr("暂停"));
            QString fileName = audio->currentSource().fileName();
            QString title = fileName.right(fileName.length() - fileName.lastIndexOf('/') - 1);
            this->setWindowTitle(title);
            ui->label_palyname->setText(title);
            trayicon->setToolTip(tr("正在播放：")+ title);
            break;
        }
    case Phonon::PausedState:
        {
            play->setIcon(*iconplay);
            ui->toolButton_playpause->setIcon(*iconplay);
            ui->toolButton_playpause->setToolTip(tr("播放"));
            ui->label_palyname->setText(tr("暂停"));
            play->setText(tr("播放"));
            trayicon->setToolTip(tr("暂停"));
            lrc->timer->stop();//停止计时

            break;
        }
    case Phonon::StoppedState:
        {
            ui->toolButton_playpause->setIcon(*iconplay);
            play->setText(tr("播放"));
            play->setIcon(*iconplay);
            this->setWindowTitle(tr("媒体播放器"));
            ui->label_palyname->setText(tr("停止"));
            trayicon->setToolTip(tr("停止"));
            ui->label_time->setText("00:00 / 00:00");
            lrc->setText("Music ...");
            ui->label_lrc->setText("Music ...");
            lrc->timer->stop();//停止计时
            break;
        }

    case Phonon::LoadingState:
        break;
    case Phonon::ErrorState:
        break;
    case Phonon::BufferingState:
        break;
    }
}

void Widget::musicAboutToFinish() //本首音乐快结束时
{
    int index = musicSourceList.indexOf(audio->currentSource()) + 1; //下一首
    if(musicSourceList.size() > index)
        audio->enqueue(musicSourceList.at(index));//注意：不会产生状态的改变state
}

void Widget::currentMusicSourceChanged(Phonon::MediaSource source)
        //当自动播放下一曲音乐时，在tableWidget中让它为选中状态
{
    mList->ui->tableWidget->selectRow(musicSourceList.indexOf(source));
    audio->pause();//在此改变一下状态触发mediaObjectStateChanged槽函数
}

void Widget::tableWidget_cellDoubleClicked(int row, int column)//双击选歌
{
    audio->stop();
    audio->clearQueue();    //清除媒体的队列

    if (row >= musicSourceList.size())
        return;
    audio->setCurrentSource(musicSourceList[row]);
    audio->play();
}

void Widget::dragEnterEvent(QDragEnterEvent *e)
{
    if(e->mimeData()->hasFormat("text/uri-list"))
            e->acceptProposedAction();
}

void Widget::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
    {
        return;
    }
    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
    {
        return;
    }
    int index = musicSourceList.size();  //获取当前列表的长度
    for(int i=0; i<urls.length(); i++)
    {
        QString string = urls.at(i).toString();
        Phonon::MediaSource source(string);
        musicSourceList.append(source);//在当前列表后加入一条记录
    }

    if(!musicSourceList.isEmpty())
       musicInformationMediaObject->setCurrentSource(Phonon::MediaSource(musicSourceList.at(index)));
}

void Widget::on_toolButton_List_clicked(bool checked)//播放列表的显示
{
    if(checked)
    {
        mList->listReadSettings();
        mList->show();
    }
    else
    {
        mList->listWriteSettings();
        mList->hide();
    }
}

