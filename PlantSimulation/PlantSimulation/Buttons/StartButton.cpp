#include "StartButton.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>

StartButton::StartButton(QWidget *parent) : QWidget(parent)
{
    timerState=false;
}

void StartButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        emit sendClicked();
        if(timerState==false)
        {
            timerState=true;
        }
        else
        {
            timerState=false;
        }
        update();
    }
}

void StartButton::getTimerState(bool _timerState)
{
    timerState=_timerState;
    qDebug()<<timerState;
    update();
}

void StartButton::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(43,37);
//    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    if(timerState==false)
    {
        painter.drawPixmap(QPoint(0,0),QPixmap("../Pictures/start.jpg"));
    }
    else
    {
        painter.drawPixmap(QPoint(0,0),QPixmap("../Pictures/suspend.jpg"));
    }

    painter.end();
    this->resize(33,29);
    painter.begin(this);

    painter.drawPixmap(0,0,pixmap);
}
