#include "CableLine.h"
#include "Widgets/PointWidget.h"
#include "Widgets/CableCanvas.h"
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QDebug>

double CableLine::Pi=3.14159;
bool CableLine::pressState=false;
//bool CableLine::enterState=false;


CableLine::CableLine(QPointF point1,QPointF point2,QString point1Name, QString point2Name,
                     int point1Num,int point2Num,double point1Length,double point2Length, QWidget *parent) : QWidget(parent)
{   
//    qDebug()<<point1<<point2;
    updateFlag=0;
    pressPoint1=point1;
    pressPoint2=point2;
    pressPoint1Name=point1Name;
    pressPoint2Name=point2Name;
    pressPoint1Num=point1Num;
    pressPoint2Num=point2Num;
    pressPoint1Length=point1Length;
    pressPoint2Length=point2Length;
    qDebug()<<pressPoint1Name<<pressPoint2Name;
    //有两个连接点，且widget自身提供前驱点，即提供的Point是后一个
    if(pressPoint1Num==2)
    {
        pressPoint1=point1+QPointF(pressPoint1Length/2,0);
//        qDebug()<<"create1:"<<pressPoint1;
    }
    //有两个连接点，且widget自身提供后继点，即提供的Point是前一个
    else if(pressPoint2Num==2)
    {
        pressPoint2=point2-QPointF(pressPoint2Length/2,0);
//        qDebug()<<"create2:"<<pressPoint2;
    }
}

#if 0
void CableLine::getPoint1(QPointF _point)
{
    point1=_point;
//    qDebug()<<"point1:"<<_point;
    update();
}

void CableLine::getPoint2(QPointF _point)
{
    point2=_point;
//    qDebug()<<"point2:"<<_point;
    update();
}
#endif

void CableLine::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        pressState=true;
        this->setFocus();
        emit sendFocus(pressState,name);//发送widget已经被选中的信号,需要将其他焦点屏蔽

        PressX=ev->globalX();//鼠标相对于桌面显示器的位置
        PressY=ev->globalY();

        A1X=this->x();//widget左上角相对于程序窗口的位置
        A1Y=this->y();

        emit sendWindowHide();

        linkPoint1=QPointF(A1X+45,A1Y+65);
//        emit sendLinkPoint(linkPoint1,name,pointNum);

    }
    update();

}


void CableLine::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        CurrentX=ev->globalX();
        CurrentY=ev->globalY();

        A2X=A1X+CurrentX-PressX;
        A2Y=A1Y+CurrentY-PressY;

        emit sendWindowHide();

        linkPoint1=QPointF(A2X+45,A2Y+65);
//        emit sendMoveLinkPoint(linkPoint1,name,pointNum);
        update();
    }
}

void CableLine::mouseReleaseEvent(QMouseEvent *ev)
{
//    pressState=false;
    updateFlag=1;
    update();

}

void CableLine::getMoveLinkPoint(QPointF _moveLinkPoint,QString _name,int _pointNum,double _widgetLength)
{
    if(_name==pressPoint1Name)
    {
        if(_pointNum==2)
        {
            pressPoint1=_moveLinkPoint+QPointF(_widgetLength/2,0);
//            qDebug()<<"pressPoint1:"<<pressPoint1;
        }
        else
        {
            pressPoint1=_moveLinkPoint;
//            qDebug()<<"movepoint1:"<<pressPoint1;
        }
        update();
    }
    else if(_name==pressPoint2Name)
    {
        if(_pointNum==2)
        {
            pressPoint2=_moveLinkPoint-QPointF(_widgetLength/2,0);
//            qDebug()<<"pressPoint2:"<<pressPoint2;
        }
        else
        {
            pressPoint2=_moveLinkPoint;
//            qDebug()<<"movepoint2:"<<pressPoint2;
        }
        update();
    }
}

void CableLine::getChangeCableLength(QPointF _linkPoint,QString _name,double _widgetLength)
{
//    qDebug()<<"linkPoint:"<<_linkPoint;
    if(_name==pressPoint2Name)
    {

        pressPoint2=_linkPoint-QPointF(_widgetLength/2,0);
//        qDebug()<<"enter2:"<<pressPoint2;
         update();
    }
    else if(_name==pressPoint1Name)
    {
        pressPoint1=_linkPoint+QPointF(_widgetLength/2,0);
//        qDebug()<<"enter1:"<<pressPoint1;
         update();
    }

}

void CableLine::getUpdate()
{
    update();
}

void CableLine::getChangeFocus(QString _name)
{
    if(_name==name&&pressState==true)
    {
        pressState=false;
//        屏蔽焦点
        this->setFocusPolicy(Qt::NoFocus);
        update();
    }
}

void CableLine::paintEvent(QPaintEvent *ev)
{

        QPixmap pixmap(1964,1200);
        pixmap.fill(Qt::transparent);

        QPainter p(&pixmap);
        p.setPen(QPen(Qt::red,1.5));
        //消除锯齿
        p.setRenderHints(QPainter::SmoothPixmapTransform);

        //绘制箭头
        double pointX=pressPoint2.x()-pressPoint1.x();
        double pointY=pressPoint2.y()-pressPoint1.y();
        double angle=atan(pointY/pointX)*double(180.0/Pi);
        double lineLength=sqrt(abs(pointX)*abs(pointX)+abs(pointY)*abs(pointY));

//        qDebug()<<pointX<<pointY<<lineLength;

//        qDebug()<<"middlePoint:"<<middlePoint<<"angle:"<<angle;

//        p.drawLine(0,25,lineLength,25);
        p.drawLine(pressPoint1.x(),pressPoint1.y(),pressPoint1.x()+lineLength,pressPoint1.y());
        p.translate(pressPoint1.x()+lineLength/2.0,pressPoint1.y());

//        p.translate(lineLength/2.0,25);
//        p.rotate(angle);
        p.drawLine(0,0,-15*cos(1.83*Pi),-15*sin(1.83*Pi));
        p.drawLine(0,0,-15*cos(-1.83*Pi),-15*sin(-1.83*Pi));
        p.translate(-(pressPoint1.x()+lineLength/2.0),-pressPoint1.y());

        p.end();
        this->resize(1924,1200);

        p.begin(this);
        p.translate(pressPoint1.x(),pressPoint1.y());
        p.rotate(angle);
        p.translate(-pressPoint1.x(),-pressPoint1.y());

        p.drawPixmap(QRectF(pressPoint1.x(),pressPoint1.y()-10,-1,-1),pixmap,QRectF(pressPoint1.x(),pressPoint1.y()-10,lineLength,20));
//        p.drawPixmap(0,0,pixmap);

//        this->move(pressPoint1.x(),pressPoint1.y());
}

void CableLine::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_Delete)
    {
//        qDebug()<<"delete";
        delete this;
        pressState=false;
    }
    else if(ev->key()==Qt::Key_Escape)
    {
//        widget通过esc取消聚焦
//        qDebug()<<"enter";
        pressState=false;
        this->setFocusPolicy(Qt::NoFocus);
        update();
        emit sendFocus(pressState,name);
    }
}

