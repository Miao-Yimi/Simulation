#ifndef CABLECANVAS_H
#define CABLECANVAS_H

#include "Widgets/Canvas.h"
#include <QWidget>

class CableCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit CableCanvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *ev);


private:
    static bool createPoint1;
    static bool createPoint2;
    QPoint point1,point2;
signals:

private slots:
    void getCreateCable();
    void getTwoPoint();
    void getLinkPoint(QPoint);

};

#endif // CABLECANVAS_H
