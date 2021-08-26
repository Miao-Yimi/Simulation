#ifndef STATIONWIDGET_H
#define STATIONWIDGET_H

#include "WidgetWindows/StationWindow.h"
#include "Widgets/FloatWindow.h"
#include <QWidget>
#include <QPoint>
#include <QKeyEvent>

class StationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StationWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *ev);//选中widget，使用delete删除对象

    StationWindow *stationWindow;
    FloatWindow *stationWorkState;
    QPointF linkPoint1;
    static int stationNum;

    bool simulationState;//控件是否处于仿真时间中
    int workState;//控件作业状态
    int timeInterval;//时间间隔
    QString workStateString;//控件作业状态：working-作业状态; blocked-阻塞状态; waiting-等待状态

protected:

private:
    //移动相关参数变量
    int A1X,A1Y;
    int A2X,A2Y;
    int PressX,PressY;
    int CurrentX,CurrentY;
    int LeftX,LeftY;
    double stationLong;//定义source长度

    QString name,stationCode;//控件名字
    double fontDis;//名字居中显示用
    QPoint leftPoint;//widget左上角点前一次坐标

    bool pressState;//控件按压状态，全局变量
    bool enterState;//控件进入状态
    int pointNum;
    int cargo,stationcargo;
    int runFlag1,runFlag2,runFlag3;

    void enterEvent(QEvent *ev);//进入事件
    void leaveEvent(QEvent *ev);//离开事件

    QVector<QString> subsequentWidget;//与该控件相连的后继控件

    //与该控件相连的后继控件的仿真状态，只有当后继控件仿真状态=true时，才可能对其进行操作
    QMap <QString,bool> subSimulationState;
    //与该控件相连的后继控件的仿真状态，只有当后继控件处于空闲状态时，才可能对其进行操作
    QMap <QString,int> subWorkState;

    int workStateNum;//从时钟那里接收到的开始作业信号的数量
    int tempTimeInterval;
    void stationWork();


signals:
    void sendWindowShow();//鼠标进入widget，悬浮窗口显示信号
    void sendWindowHide();
    void sendFocus(bool,QString);//发送widget被选中、聚焦的信号
    void sendLinkPoint(QPointF,QString,int,double);
    void sendMoveLinkPoint(QPointF,QString,int,double);
    void sendStartSimulation(QString);
    void sendEndSimulation(QString);
    void sendWorkState(QString,int);
    void sendCargo(QString);//加工完成的零部件发送到下一个widget
    void sendDeleteWidget(QString);//删除widget，要将这个信号发送给前驱widget，将其后继widget数组中的Name删除

private slots:
    void getName(QString,int);
    void getUpdate();
    void getWindowShow();//显示悬浮窗口
    void getWindowHide();//隐藏悬浮窗口
    void getChangeFocus(QString);//改变焦点
    void getRaise();
    void getStationNumber(int);
    void getStartSimulation(QString);
    void getEndSimulation(QString);
    void getSubsequent(QString,QString);
    void getSubStartSimulation(QString);
    void getSubEndSimulation(QString);
    void getStationWork(int,QString);//Station从时钟获取开始作业的信号，准备发送货物
    void getTimeInterval(int);
    void getCargo(QString);//Station从Source获取货物信号
    void getWorkState(QString,int);
    void sendCargoToSub();
    void getDeleteWidget(QString);
    void getSpeedUp();
    void getSpeedDown();
    void getTimerRemake();
};

#endif // STATIONWIDGET_H
