#ifndef POINTWIDGET_H
#define POINTWIDGET_H

#include <QWidget>

class PointWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PointWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *ev);

    QPoint point;

private:
    //移动相关参数变量
    int A1X,A1Y;
    int A2X,A2Y;
    int PressX,PressY;
    int CurrentX,CurrentY;

    bool pointShow;
    bool pointState;//该点是否已经确定

signals:
    void sendCurrentPoint(QPoint);//发送当前点的坐标
    void sendFinishPoint();

private slots:
    void getMousePoint(int,int);

};

#endif // POINTWIDGET_H
