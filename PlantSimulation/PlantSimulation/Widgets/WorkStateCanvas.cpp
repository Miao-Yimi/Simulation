#include "WorkStateCanvas.h"
#include "Widgets/FloatWindow.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>

WorkStateCanvas::WorkStateCanvas(QWidget *parent) : QWidget(parent)
{

}

void WorkStateCanvas::getCreateStationWindow()
{
    FloatWindow *stationWindow=new FloatWindow(this);
    stationWindow->hide();
}

void WorkStateCanvas::getStationShow()
{
//    qDebug()<<"show";
    FloatWindow *stationWindow=new FloatWindow(this);
    stationWindow->show();
}

void WorkStateCanvas::getStationHide()
{
//    qDebug()<<"hide";
    FloatWindow *stationWindow=new FloatWindow(this);
    stationWindow->hide();}

void WorkStateCanvas::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(1964,1200);
    pixmap.fill(Qt::white);
    QPainter p(&pixmap);

    p.end();
//    this->resize(1000,600);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);
}
