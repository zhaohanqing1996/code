#include "chessboard.h"

ChessBoard::ChessBoard(QWidget *parent)
    : QWidget(parent)
{
    memberInit();
}

ChessBoard::~ChessBoard()
{

}

void ChessBoard::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(4);

    painter.setPen(pen);

    // 1.绘制棋盘网格
    drawGrid(&painter);
    this->setMinimumSize(14*sideLength+2*topWidth, 14*sideLength+2*topHeight);
    this->setMaximumSize(14*sideLength+2*topWidth, 14*sideLength+2*topHeight);
    this->setStyleSheet(QString("background-color: rgb(233, 206, 159);"));

    // 2.根据信息表，绘制棋子
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(info[i][j] == WhiteChess)
            {
                QPoint p = getpixPosByIJ(i, j);
                painter.drawPixmap(p, QPixmap(":/images/white.png"));
            }
            else if(info[i][j] == BlackChess)
            {
                QPoint p = getpixPosByIJ(i, j);
                painter.drawPixmap(p, QPixmap(":/images/black.png"));
            }
        }
    }
}

void ChessBoard::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(isCanDropChess(e->x(),e->y()))
        {
            qDebug() << "落棋";
            QPoint ij = getIJByMousePos(e->x(), e->y());
            int i = ij.x();
            int j = ij.y();
            if(info[i][j] == NoChess)
            {
                info[i][j] = drop;
                this->update();
                if(drop == BlackChess)
                {
                    drop = WhiteChess;
                }
                else
                {
                    drop = BlackChess;
                }
            }
        }
    }
}

void ChessBoard::mouseMoveEvent(QMouseEvent *e)
{
    if(isCanDropChess(e->x(), e->y()))
    {
        this->setCursor(QCursor(Qt::PointingHandCursor));
    }
    else
    {
        this->setCursor(QCursor(Qt::ArrowCursor));
    }

}

void ChessBoard::memberInit()
{
    topWidth = 30;
    topHeight = 40;
    sideLength = 50;

    checkSide = 10;
    drop = BlackChess;

    chessPath = ":/images/black.png";

    this->setMouseTracking(true);

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            info[i][j] = NoChess;
        }
    }
    info[2][4] = BlackChess;
}

void ChessBoard::drawGrid(QPainter *p)
{
    for(int i = 0; i < 15; i++)
    {
        p->drawLine(topWidth,topHeight+i*sideLength, topWidth+14*sideLength,topHeight+i*sideLength);
        p->drawLine(topWidth+i*sideLength,topHeight, topWidth+i*sideLength,topHeight+14*sideLength);
    }
}

bool ChessBoard::isCanDropChess(int mx, int my)
{
    if(mx < topWidth-checkSide || mx > topWidth+14*sideLength+checkSide)
    {
        return false;
    }
    if(my < topHeight-checkSide || my > topHeight+14*sideLength+checkSide)
    {
        return false;
    }

    QPoint ij = getIJByMousePos(mx, my);

    QPoint point = getPosByIndex(ij.x(), ij.y());
    if(mx < point.x()-10 || mx > point.x()+10)
    {
        return false;
    }
    if(my < point.y()-10 || my > point.y()+10)
    {
        return false;
    }
    return true;
}

QPoint ChessBoard::getPosByIndex(int i, int j)
{
    return QPoint(j * sideLength + topWidth, i * sideLength + topHeight);
}

QPoint ChessBoard::getPixPosByMousePos(int mx, int my)
{
    QPoint ij = getIJByMousePos(mx, my);
    return getpixPosByIJ(ij.x(), ij.y());
}

QPoint ChessBoard::getpixPosByIJ(int i, int j)
{
    QPoint point = getPosByIndex(i, j);

    return QPoint(point.x()-20, point.y()-20);
}

QPoint ChessBoard::getIJByMousePos(int mx, int my)
{
    int px = (mx - topWidth) % sideLength;
    int py = (my - topHeight) % sideLength;
    int i = (my - topHeight) / sideLength;
    int j = (mx - topWidth) / sideLength;

    if(px > sideLength/2)
    {
        j++;
    }
    if(py > sideLength/2)
    {
        i++;
    }
    return QPoint(i, j);
}
