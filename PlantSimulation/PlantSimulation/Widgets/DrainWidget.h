#ifndef DRAINWIDGET_H
#define DRAINWIDGET_H
#include "WidgetWindows/DrainWindow.h"
#include "Widgets/FloatWindow.h"
#include <QWidget>
#include <QPoint>
#include <QKeyEvent>

class DrainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrainWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *ev);//选中widget，使用delete删除对象

    DrainWindow *drainWindow;
    FloatWindow *drainWorkState;
    QPointF linkPoint1,linkPoint2;

    static int drainNum;
    bool simulationState;//控件是否处于仿真时间中
    int workState;
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
    double drainLong;//定义source长度

    QString name,drainCode;//控件名字
    double fontDis;//名字居中显示用
    QPoint leftPoint;//widget左上角点前一次坐标
    int runFlag1,runFlag2;

    bool pressState;//控件按压状态，全局变量
    bool enterState;//控件进入状态
    int pointNum;
    int workStateNum;
    bool cargo;//是否收到货物
    int tempTimeInterval;

    void enterEvent(QEvent *ev);//进入事件
    void leaveEvent(QEvent *ev);//离开事件
    void drainWork();

signals:
    void sendWindowShow();//鼠标进入widget，悬浮窗口显示信号
    void sendWindowHide();
    void sendFocus(bool,QString);//发送widget被选中、聚焦的信号
    void sendLinkPoint(QPointF,QString,int,double);
    void sendMoveLinkPoint(QPointF,QString,int,double);
    void sendStartSimulation(QString);
    void sendEndSimulation(QString);
    void sendWorkState(QString,int);
    void sendDeleteWidget(QString);//删除widget，要将这个信号发送给前驱widget，将其后继widget数组中的Name删除

private slots:
    void getName(QString,int);
    void getUpdate();
    void getWindowShow();//显示悬浮窗口
    void getWindowHide();//隐藏悬浮窗口
    void getChangeFocus(QString);//改变焦点
    void getRaise();
    void getDrainNumber(int);
    void getStartSimulation(QString);
    void getEndSimulation(QString);
    void getDrainWork(int,QString);//Drain从时钟获取开始作业的信号，准备接收货物
    void changeWorkState();
    void getTimeInterval(int);
    void getCargo(QString);//Drain从Station获取货物信号
    void getSpeedUp();
    void getSpeedDown();
    void getTimerRemake();

};

#endif // DRAINWIDGET_H
