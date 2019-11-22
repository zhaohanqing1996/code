#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QDebug>
#include <QCursor>

class ChessBoard : public QWidget
{
    Q_OBJECT

public:
    enum ChessType{NoChess, BlackChess, WhiteChess};

public:
    ChessBoard(QWidget *parent = 0);
    ~ChessBoard();
protected:
    void paintEvent(QPaintEvent *e);

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);        // 提供落棋提示功能


private:
    void memberInit();

    void drawGrid(QPainter *p);

    bool isCanDropChess(int mx, int my);

    QPoint getPosByIndex(int i, int j);
    QPoint getPixPosByMousePos(int mx, int my);
    QPoint getpixPosByIJ(int i, int j);
    QPoint getIJByMousePos(int mx, int my);



private:
    int topWidth;       // 顶边距宽度
    int topHeight;      // 顶边距高度

    int sideLength;     // 边长

    int checkSide;      // 检测区域边长

    ChessType drop;     // 落棋类型
    QString chessPath;         // 图片路径

    ChessType info[15][15];    // 保存棋盘棋子信息      指导绘制的方案

};

#endif // CHESSBOARD_H
