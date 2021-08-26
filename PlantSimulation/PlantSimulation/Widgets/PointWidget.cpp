#include "PointWidget.h"
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>

PointWidget::PointWidget(QWidget *parent) : QWidget(parent)
{
    point.setX(0);
    point.setY(0);
    A2X=point.x();
    A2Y=point.y();
    pointShow=false;//不显示点
    pointState=false;//该点未确定
}

//修改初始A2X,A2Y值
void PointWidget::getMousePoint(int _A2X,int _A2Y)
{
//获取的是鼠标点相对于桌面的全球坐标，但实际移动距离是在canvas中，需要减去canvas与mainwindow之间的相对距离
//x方向相对距离是200，y方向相对距离是234
    if(pointState==false)
    {
        pointShow=true;
        pointState=true;
        A2X=_A2X-200;
        A2Y=_A2Y-234;

    //    点的初始坐标
        point.setX(A2X);
        point.setY(A2Y);
        emit sendCurrentPoint(point);//发送当前点的坐标给cableline

//        qDebug()<<point;
        update();
    }
}

void PointWidget::paintEvent(QPaintEvent *ev)
{
//    if(pointShow==true)
//    {
        QPixmap pixmap(10,10);//控件画布大小为10*10
        pixmap.fill(Qt::transparent);
        QPainter p(&pixmap);
        p.setPen(QPen(Qt::red,10));

        p.drawPoint(0,0);

        p.end();
        this->resize(10,10);
        p.begin(this);

        p.drawPixmap(0,0,pixmap);
        this->move(A2X,A2Y);
//    }
}
