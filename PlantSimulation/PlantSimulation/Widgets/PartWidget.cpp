#include "PartWidget.h"
#include <QPixmap>
#include <QPainter>
#include <QDebug>

PartWidget::PartWidget(QWidget *parent) : QWidget(parent)
{

}

void PartWidget::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap(26,26);//控件图标大小为90*130
    QPainter p(&pixmap);

    p.drawPixmap(QPoint(0,0),QPixmap("../Pictures/part.jpg"));

    p.end();
    this->resize(26,26);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);
}
