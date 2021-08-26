#ifndef CANVAS_H
#define CANVAS_H

#include "Widgets/ClockWidget.h"
#include "Widgets/PointWidget.h"
#include "Widgets/CableCanvas.h"
#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev);

    void paintEvent(QPaintEvent *ev);

    static bool widgetPressState;//总的按压状态
    static bool PressState;//画布按压状态

    static int stationNum;
    static int sourceNum;
    static int drainNum;

    int PressX,PressY;
    ClockWidget* clockWidget;

protected:
    QString pressedWidget;//当前被聚焦的widget

    /*一个前驱点可以有多个后继点，当前驱点坐标发生变化时，与后继点相连的所有cableLine都发生变化
      当后继点坐标发生变化时，只有与该后继点相关的cableLine发生变化
     */
    QMap<QString,QVector<QString>> cablePointName;//每个前驱点对应的多个后继点
    QMap<QString,QPointF> cablePoint;//每个点对应的坐标
    QMap<QString,int> cablePointNum;

private:
    static bool createPoint1;
    static bool createPoint2;
    static bool createCable;
    static double Pi;
    static int count;

    QPointF point1,point2;
    QString point1Name,point2Name;
    int point1Num,point2Num;
    double point1Length,point2Length;

signals:
    void sendCancleFocus(QString);//发送取消聚焦信号
    void sendMousePoint(int,int);//发送此时鼠标在画布上的点击点
    void sendPoint1(int,int);
    void sendPoint2(int,int);
    void sendUpdate();
    void sendRaise();
    void sendMoveLinkPoint(QPointF,QString,int,double);
    void sendNumber(int);//发送工作站创建的数量以修改工作站name
    void sendSubsequent(QString,QString);//将后继节点Point2发送给Point1所在的控件
    void sendSubStartSimulation(QString);
    void sendSubEndSimulation(QString);
    void sendCargo(QString);
    void sendWorkState(QString,int);
    void sendWantWork(QString);
    void sendDeleteWidget(QString);
    void sendChangeCableLength(QPointF,QString,double);

private slots:
    void getCreateStation();
    void getCreateSource();
    void getCreateDrain();
    void getCreateTrans();
    void getWidgetPressState(bool,QString);//当前界面是否已有widget被选中，即被聚焦
    void getTwoPoint();
    void getCreateCable();
    void getLinkPoint(QPointF,QString,int,double);
    void getMoveLinkPoint(QPointF,QString,int,double);
    void getStartSimulation(QString);
    void getEndSimulation(QString);
    void getWorkState(QString,int);
    void getCargo(QString);
    void getDeleteWidget(QString);
    void getChangeCableLength(QPointF,QString,double);
};

#endif // CANVAS_H
