#include "DownButton.h"
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

DownButton::DownButton(QWidget *parent) : QWidget(parent)
{

}

void DownButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        emit sendClicked();
    }
}

void DownButton::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(33,29);
    QPainter painter(&pixmap);

    painter.drawPixmap(QPoint(0,0),QPixmap("../Pictures/down.jpg"));

    painter.end();
    this->resize(33,29);
    painter.begin(this);

    painter.drawPixmap(0,0,pixmap);
}
