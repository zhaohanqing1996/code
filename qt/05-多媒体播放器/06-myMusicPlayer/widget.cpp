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
    mList->setFixedSize(300,320);//�̶������б�Ĵ�С
    mList->ui->tableWidget->setColumnWidth(0,150);//���õ�0�еĿ��
    mList->ui->tableWidget->setColumnWidth(1,150);//���õ�1�еĿ��
    connect(mList->ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),SLOT(tableWidget_cellDoubleClicked(int,int)));
    //mList->show();
    connect(mList,SIGNAL(listClose()),ui->toolButton_List,SLOT(toggle()));

    text = new QTextEdit(this);
    text->hide();   //���� ���ڲ����¾����Լ���ʱ����
    ui->textEdit->setVisible(false);//�ı��༭�򲻿ɼ�����������ʣ�
    this->setAcceptDrops(true);
    this->setFixedSize(300,150);
    this->setWindowTitle(tr("���ֲ�����"));
    readSettings();                 //��ȡ�ϴιرմ���ʱ���ڵ�λ��

    QPalette palette = ui->label_lrc->palette();//���ô����ڸ����ɫ
    palette.setColor(QPalette::WindowText,Qt::darkBlue);
    ui->label_lrc->setPalette(palette);

    lrc = new lrcWindow(0);//������
  //  lrc->show();

    /**��ʼ��ý��**/
    audio =new Phonon::MediaObject();//ý�����
    audio->setTickInterval(1);//������԰�����������֮���ʱ�����Ժ���Ϊ��λ
    audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory);//��Ƶ���
    Phonon::createPath(audio,audioOutput);//����ý���������Ƶ���

    musicInformationMediaObject = new Phonon::MediaObject(this);  //������Ϣ����

    volumeSlider = new Phonon::VolumeSlider(audioOutput,this);  //����������
    volumeSlider->move(190,80);
    volumeSlider->resize(50,20);
    volumeSlider->setStyleSheet("background-color:rgb(255,255,255,100)");
    volumeSlider->setFixedWidth(100);//�̶���������С

    seekSlider = new Phonon::SeekSlider(audio,this); //���Ȼ�����
    seekSlider->move(10,35);
    seekSlider->resize(170,20);
    seekSlider->setStyleSheet("background-color:rgb(255,255,255,100)");

    connect(audio,SIGNAL(tick(qint64)),this,SLOT(showTime(qint64)));//ʱ����ʾ���ʵĸ���
    connect(audio,SIGNAL(stateChanged(Phonon::State,Phonon::State)),this,SLOT(mediaObjectStateChanged(Phonon::State,Phonon::State)));
    connect(musicInformationMediaObject,SIGNAL(stateChanged(Phonon::State,Phonon::State)),this, SLOT(musicInformationStateChanged(Phonon::State,Phonon::State)));
    //������������ʱִ��
    connect(audio,SIGNAL(aboutToFinish()),this,SLOT(musicAboutToFinish()));
    connect(audio,SIGNAL(currentSourceChanged(Phonon::MediaSource)),this,SLOT(currentMusicSourceChanged(Phonon::MediaSource)));

    connect(lrc->exit,SIGNAL(triggered(bool)),ui->toolButton_lrcD,SLOT(setChecked(bool)));

    timer = new QTimer(this);//��ʱ������0.1�벻��ʾ��ʣ�����ʾ��Music ...��
    timer->start(100);
    connect(timer,SIGNAL(timeout()),SLOT(Timeout()));

    creatActions();
    mList->installEventFilter(this);                //��װ�¼�������
    mList->ui->tableWidget->installEventFilter(this);//�¼�������
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

      //ֻ�Ա�������Χ�ڵ�����¼����д���
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

void Widget::readSettings()//��ȡ�����ڵ�λ����Ϣ
{
    QSettings settings("yafeilinux", "Phonon Example");
    QPoint pos = settings.value("pos", QPoint(400,200)).toPoint();
    //QSize size = settings.value("size", QSize(298,412)).toSize();
    move(pos);
    //resize(size);
}

void Widget::writeSettings()//��¼�����ڵ�λ����Ϣ
{
    QSettings settings("yafeilinux","Phonon Example");
    settings.setValue("pos", pos());
    //settings.setValue("size", size());
}

void Widget::closeEvent(QCloseEvent *e)//�ر��¼�
{
    writeSettings();
    mList->listWriteSettings();
    if(this->isVisible())
    {
        this->hide();
        mList->hide();
        trayicon->showMessage(tr("���ֲ�����"),tr("��С����ϵͳ���̣�Ҫ�ر����һ���ͼ��ѡ���˳�����"),QSystemTrayIcon::Information,15000);
        e->ignore();
    }
}

bool Widget::eventFilter(QObject *object, QEvent *event)
{qDebug() << object;
    if(object == mList->ui->tableWidget)//���˱����¼�
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

void Widget::removeSlot()//����б�
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

void Widget::wheelEvent(QWheelEvent *wheelevent)//�����¼�
{
    if(wheelevent->delta() > 0 )//�Ϲ�
    {
       qreal newvolume = audioOutput->volume() + (qreal)0.05;
        if(newvolume >= (qreal)1)
            newvolume = (qreal)1;
        audioOutput->setVolume(newvolume);
    }
    else//�¹�
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

void Widget::setCurrentLrc()//���õ�ǰ�����ʾ
{
    QString fileName = audio->currentSource().fileName();

    QString lrcName = fileName.remove(fileName.right(3)) + "lrc";
    QFile file(lrcName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        ui->label_lrc->setText(tr("��ǰĿ¼��δ�ҵ�����ļ�"));
        lrc->setText(tr("��ǰĿ¼��δ�ҵ�����ļ�"));
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
}

void Widget::Timeout()//��0.1�벻��ʾ��ʣ�����ʾ����������֡�
{
    if(lrc->text().isEmpty())
    {
        lrc->setText(tr("���������"));
        ui->label_lrc->setText(tr("���������"));
    }
}
void Widget::showTime(qint64 time)//ʱ�����ʵĸ�����ʾ
{
    qint64 temp = audio->totalTime();
    QTime totalTime(0,(temp / 60000) % 60,(temp / 1000) % 60,time %1000);
    QTime curTime(0,(time / 60000) % 60,(time / 1000) % 60,time %1000);
        ui->label_time->setText(tr("%1 / %2")
                       .arg(curTime.toString("mm:ss"))
                       .arg(totalTime.toString("mm:ss")));
    ui->label_time->update();
    /**��ʵĸ�����ʾ**/

    if(ui->textEdit->find(curTime.toString("mm:ss.zzz").left(7)))//�����
    {
        QString str = ui->textEdit->textCursor().block().text().replace(QRegExp("\\[\\d{2}:\\d{2}\\.\\d{2}\\]"),"");

        ui->label_lrc->setText(str);
        lrc->setText(str);
        lrc->setLrcWidth();//������������label�Ŀ��Ϊ0
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

    }//�Ҳ�������ǰ��
    else if(ui->textEdit->find(curTime.toString("mm:ss.zzz").left(7),QTextDocument::FindBackward))
    {
        QString str = ui->textEdit->textCursor().block().text().replace(QRegExp("\\[\\d{2}:\\d{2}\\.\\d{2}\\]"),"");
        ui->label_lrc->setText(str);
        lrc->setText(str);
        lrc->setLrcWidth();//������������label�Ŀ��Ϊ0

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

    remove = new QAction(iconremove,tr("��ղ����б�"),this);
    connect(remove,SIGNAL(triggered()),this,SLOT(removeSlot()));

    play = new QAction(*iconplay,tr("����"),this);
    connect(play,SIGNAL(triggered()),this,SLOT(on_toolButton_playpause_clicked()));

    stop = new QAction(iconstop,tr("ֹͣ"),this);
    connect(stop,SIGNAL(triggered()),audio,SLOT(stop()));

    open = new QAction(iconopen,tr("���ļ�"),this);
    connect(open,SIGNAL(triggered()),this,SLOT(on_toolButton_open_clicked()));

    sound = new QAction(iconsound,tr("����"),this);
    sound->setCheckable(true);
    connect(sound,SIGNAL(triggered(bool)),audioOutput,SLOT(setMuted(bool)));

    exit = new QAction(iconexit,tr("�˳�"),this);
    connect(exit,SIGNAL(triggered()),this,SLOT(exitSlot()));

    /***ϵͳ����****/
    trayicon = new QSystemTrayIcon(this);  //ϵͳ����
    QIcon ico(":/images/VMP2.png");
    trayiconMenu = new QMenu(this);
    trayiconMenu->addAction(play);
    trayiconMenu->addAction(stop);
    trayiconMenu->addAction(open);
    trayiconMenu->addSeparator();
    trayiconMenu->addAction(exit);

    trayicon->setIcon(ico);
    trayicon->setToolTip(tr("���ڲ��ţ�"));
    trayicon->setContextMenu(trayiconMenu);  //�����õĲ˵���ӵ�ϵͳ����

    trayicon->show();
    trayicon->showMessage(tr("���ֲ�����"),tr("��ӭ���ʣ�www.yafeilinux.com"),QSystemTrayIcon::Information,10000);

    connect(trayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));//ͼ�걻����ʱ

}

void Widget::exitSlot()//���̲˵��Ĺر�
{
    this->hide();
    this->close();
}

void Widget::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::Trigger://����
        case QSystemTrayIcon::DoubleClick://˫��
          //  this->readSettings();
            this->setWindowState(Qt::WindowActive);//�ָ�������ʾ
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

void Widget::on_toolButton_open_clicked()//��
{
    QStringList list = QFileDialog::getOpenFileNames(this,tr("�������ļ�"), QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    if(list.isEmpty()) return;
    int index = musicSourceList.size();  //��ȡ��ǰ�б�ĳ���
    foreach(QString string,list)         //foreach�ؼ��ֿ���ѭ������list��������ݣ����Ƹ�string
    {
        Phonon::MediaSource source(string);
        musicSourceList.append(source);//�ڵ�ǰ�б�����һ����¼
    }
    if(!musicSourceList.isEmpty())
        musicInformationMediaObject->setCurrentSource(musicSourceList.at(index));
    //���¼���ĵ�һ����¼��ӵ�musicInformationMediaObject
}

void Widget::on_toolButton_previous_clicked()//��һ��
{
    int index = musicSourceList.indexOf(audio->currentSource()) - 1;
    if(index >= 0)
    {
        audio->stop();
        audio->setCurrentSource(musicSourceList.at(index));
        audio->play();
    }

}
void Widget::on_toolButton_playpause_clicked()//����/��ͣ
{
    if(audio->state() == Phonon::PlayingState)  audio->pause();
    else
    {
        audio->play();
    }

}

void Widget::on_toolButton_stop_clicked()//ֹͣ
{
    audio->stop();
}

void Widget::on_toolButton_next_clicked()//��һ��
{
    int index = musicSourceList.indexOf(audio->currentSource()) + 1;
    if(index < musicSourceList.size())
    {
        audio->stop();
        audio->setCurrentSource(musicSourceList.at(index));
        audio->play();
    }
}

void Widget::on_toolButton_lrcD_clicked(bool checked)//��ʾ������
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
    if (newState != Phonon::StoppedState && newState != Phonon::PausedState) return;  //���������䣬��Ȼ�����б��п��ܳ����ظ�����
    /************
    �տ�ʼ��ý���������Phonon::LoadingState״̬����ʱ��˽�����Դ�����롣
    ��Phonon::LoadingState��ɺ�ͻ����Phonon::StoppedState ״̬��
    ��ʱ��������µ���Դ��
    ************/
    if (musicInformationMediaObject->currentSource().type() == Phonon::MediaSource::Invalid)return;

    QMap<QString, QString> metaData = musicInformationMediaObject->metaData();

    int rowNum = mList->ui->tableWidget->rowCount();
    mList->ui->tableWidget->insertRow(rowNum);//����һ��

    QString title = metaData.value("TITLE");  //��������
    if (title == "")
    {
        QString fileName = musicInformationMediaObject->currentSource().fileName();
        QString mp3Name = fileName.right(fileName.length() - fileName.lastIndexOf('/') - 1);
        title = mp3Name;
    }
     QTableWidgetItem *titleItem = new QTableWidgetItem(title);
     mList->ui->tableWidget->setItem(rowNum,0,titleItem);

     QTableWidgetItem *artistItem = new QTableWidgetItem(metaData.value("ARTIST")); //����
     mList->ui->tableWidget->setItem(rowNum,1,artistItem);

     qint64 tTime = musicInformationMediaObject->remainingTime();
     QTime tolTime(0,(tTime / 60000) % 60,(tTime / 1000) % 60);
     QString time = tolTime.toString("mm:ss");

     QTableWidgetItem *totalTime = new QTableWidgetItem(time); //ר��
     mList->ui->tableWidget->setItem(rowNum,2,totalTime);

     mList->ui->tableWidget->close();//�б������ʾ��ȫ
     mList->ui->tableWidget->show();

     if (mList->ui->tableWidget->selectedItems().isEmpty())
     { //���û��ѡ����
         mList->ui->tableWidget->selectRow(0);   //ѡ���һ��
         audio->setCurrentSource(musicInformationMediaObject->currentSource());
     }
     int index = musicSourceList.indexOf(musicInformationMediaObject->currentSource()) + 1;
     if (musicSourceList.size() > index) //�����δ������
     {
         musicInformationMediaObject->setCurrentSource(musicSourceList.at(index));
     }  //������һ�׸���

     if(audio->state() != Phonon::PlayingState)//�򿪺󲥷�
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
            setCurrentLrc();//�򿪸���ļ�
            play->setIcon(*iconpause);
            ui->toolButton_playpause->setIcon(*iconpause);
            ui->toolButton_playpause->setToolTip(tr("��ͣ"));
            play->setText(tr("��ͣ"));
            QString fileName = audio->currentSource().fileName();
            QString title = fileName.right(fileName.length() - fileName.lastIndexOf('/') - 1);
            this->setWindowTitle(title);
            ui->label_palyname->setText(title);
            trayicon->setToolTip(tr("���ڲ��ţ�")+ title);
            break;
        }
    case Phonon::PausedState:
        {
            play->setIcon(*iconplay);
            ui->toolButton_playpause->setIcon(*iconplay);
            ui->toolButton_playpause->setToolTip(tr("����"));
            ui->label_palyname->setText(tr("��ͣ"));
            play->setText(tr("����"));
            trayicon->setToolTip(tr("��ͣ"));
            lrc->timer->stop();//ֹͣ��ʱ

            break;
        }
    case Phonon::StoppedState:
        {
            ui->toolButton_playpause->setIcon(*iconplay);
            play->setText(tr("����"));
            play->setIcon(*iconplay);
            this->setWindowTitle(tr("ý�岥����"));
            ui->label_palyname->setText(tr("ֹͣ"));
            trayicon->setToolTip(tr("ֹͣ"));
            ui->label_time->setText("00:00 / 00:00");
            lrc->setText("Music ...");
            ui->label_lrc->setText("Music ...");
            lrc->timer->stop();//ֹͣ��ʱ
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

void Widget::musicAboutToFinish() //�������ֿ����ʱ
{
    int index = musicSourceList.indexOf(audio->currentSource()) + 1; //��һ��
    if(musicSourceList.size() > index)
        audio->enqueue(musicSourceList.at(index));//ע�⣺�������״̬�ĸı�state
}

void Widget::currentMusicSourceChanged(Phonon::MediaSource source)
        //���Զ�������һ������ʱ����tableWidget������Ϊѡ��״̬
{
    mList->ui->tableWidget->selectRow(musicSourceList.indexOf(source));
    audio->pause();//�ڴ˸ı�һ��״̬����mediaObjectStateChanged�ۺ���
}

void Widget::tableWidget_cellDoubleClicked(int row, int column)//˫��ѡ��
{
    audio->stop();
    audio->clearQueue();    //���ý��Ķ���

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
    int index = musicSourceList.size();  //��ȡ��ǰ�б�ĳ���
    for(int i=0; i<urls.length(); i++)
    {
        QString string = urls.at(i).toString();
        Phonon::MediaSource source(string);
        musicSourceList.append(source);//�ڵ�ǰ�б�����һ����¼
    }

    if(!musicSourceList.isEmpty())
       musicInformationMediaObject->setCurrentSource(Phonon::MediaSource(musicSourceList.at(index)));
}

void Widget::on_toolButton_List_clicked(bool checked)//�����б����ʾ
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

