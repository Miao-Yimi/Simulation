#include "ClockWidget.h"
#include <QPixmap>
#include <QPainter>

ClockWidget::ClockWidget(QWidget *parent) : QWidget(parent)
{
    clockWindow=new ClockWindow;
    clockWindow->hide();
    clockWindow->setFixedSize(630,230);
}

void ClockWidget::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(93,125);
    pixmap.fill(Qt::transparent);
    QPainter p(&pixmap);

    int font=fontMetrics().width("Clock");
    p.drawText((90-font)/2,110,"Clock");
    p.setPen(Qt::white);
    p.drawPixmap(QPoint(0,0),QPixmap("../Pictures/clock.jpg"));

    p.end();
    this->resize(93,125);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);
}

void ClockWidget::mouseDoubleClickEvent(QMouseEvent *ev)
{
    clockWindow->show();
}

void ClockWidget::getRaise()
{
    this->raise();
}
