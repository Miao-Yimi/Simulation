#include "CableCanvas.h"
#include "CableLine.h"
#include "Widgets/Canvas.h"
#include <QDebug>
#include <QPixmap>
#include <QPainter>

bool CableCanvas::createPoint1=false;
bool CableCanvas::createPoint2=false;

CableCanvas::CableCanvas(QWidget *parent) : QWidget(parent)
{

}


void CableCanvas::getCreateCable()
{
    qDebug()<<"enter";
    CableLine *cableLine=new CableLine(point1,point2,this);
    cableLine->show();
}

void CableCanvas::getTwoPoint()
{
    createPoint1=true;
    createPoint2=true;
}

void CableCanvas::getLinkPoint(QPoint _linkPoint)
{
    if(createPoint1==true)
    {
        createPoint1=false;
        point1=_linkPoint;
        qDebug()<<"point1:"<<point1;
    }
    else if(createPoint2==true)
    {
        createPoint2=false;
        point2=_linkPoint;
        qDebug()<<"point2:"<<point2;
        getCreateCable();
    }
}

void CableCanvas::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(1964,1200);
    pixmap.fill(Qt::white);
    QPainter p(&pixmap);

    p.end();
    this->resize(1964,1200);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);
}
