#include "FloatWindow.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QLabel>

FloatWindow::FloatWindow(QWidget *parent) : QDialog(parent)
{
    state="Standby";//待机状态

    label=new QLabel("State:",this);
    label->setGeometry(10,10,55,30);

    label2=new QLabel(state,this);
    qDebug()<<fontMetrics().width(state);
    label2->setGeometry(70,10,70,30);

    this->resize(150,65);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:rgb(255,218,185)");
    this->setWindowOpacity(0.9);
}


void FloatWindow::getWorkState(QString _workState)
{
    label2->setText(_workState);
}
#if 0
void FloatWindow::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap(150,65);//控件图标大小为90*130
    pixmap.fill(Qt::yellow);

    QPainter p(&pixmap);
    p.drawText(10,10,state);

    p.end();
    this->resize(150,65);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);

}
#endif
