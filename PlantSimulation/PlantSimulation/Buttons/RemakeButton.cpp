#include "RemakeButton.h"
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

RemakeButton::RemakeButton(QWidget *parent) : QWidget(parent)
{

}
void RemakeButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        emit sendClicked();
    }
}

void RemakeButton::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(33,29);
    QPainter painter(&pixmap);

    painter.drawPixmap(QPoint(0,0),QPixmap("../Pictures/remake.jpg"));

    painter.end();
    this->resize(33,29);
    painter.begin(this);

    painter.drawPixmap(0,0,pixmap);
}
