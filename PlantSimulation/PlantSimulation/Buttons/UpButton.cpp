#include "UpButton.h"
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

UpButton::UpButton(QWidget *parent) : QWidget(parent)
{

}

void UpButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        emit sendClicked();
    }
}

void UpButton::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(33,29);
    QPainter painter(&pixmap);

    painter.drawPixmap(QPoint(0,0),QPixmap("../Pictures/up.jpg"));

    painter.end();
    this->resize(33,29);
    painter.begin(this);

    painter.drawPixmap(0,0,pixmap);
}
