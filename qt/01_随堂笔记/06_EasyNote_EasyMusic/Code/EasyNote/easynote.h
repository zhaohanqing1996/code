#ifndef EASYNOTE_H
#define EASYNOTE_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QProcess>

namespace Ui {
class EasyNote;
}

class EasyNote : public QMainWindow
{
    Q_OBJECT

public:
    explicit EasyNote(QWidget *parent = 0);
    ~EasyNote();

public:
    void updateTitle();

public slots:
    void newFileSlot();         // 新建文件
    void openFileSlot();        // 打开文件
    void saveFileAsSlot();      // 另存为
    void saveFileSlot();        // 保存文件
    void updateChangeState();   // 更新修改状态

private:
    Ui::EasyNote *ui;
    bool hasTarget;             // 是否有目标文件
    bool isChange;              // 是否修改了未保存

    QString targetFilePath;     // 目标文件名（含路径）用于打开，读写
    QString targetFileName;     // 目标文件名（无路径）用于标题显示
};

#endif // EASYNOTE_H
