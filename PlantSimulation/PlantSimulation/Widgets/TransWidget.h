#ifndef TRANSWIDGET_H
#define TRANSWIDGET_H

#include "WidgetWindows/TransWindow.h"
#include <QWidget>
#include <QPoint>
#include <QKeyEvent>

class TransWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TransWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *ev);//选中widget，使用delete删除对象

    TransWindow *transWindow;
    QPointF linkPoint1;
    static int transNum;

private:
    int A1X,A1Y;
    int A2X,A2Y;
    int PressX,PressY;
    int CurrentX,CurrentY;
    int LeftX,LeftY;
    double transLong;//定义传送带长度

    QString name,transCode;//控件名字
    double fontDis;//名字居中显示用

    bool pressState;//控件按压状态，全局变量
    bool enterState;//控件进入状态
    int pointNum;//控件有几个端口可以被连接

    QVector<QString> subsequentWidget;//与该控件相连的后继控件

signals:
    void sendWindowShow();//鼠标进入widget，悬浮窗口显示信号
    void sendWindowHide();
    void sendFocus(bool,QString);//发送widget被选中、聚焦的信号
    void sendLinkPoint(QPointF,QString,int,double);
    void sendMoveLinkPoint(QPointF,QString,int,double);
    void sendDeleteWidget(QString);//删除widget，要将这个信号发送给前驱widget，将其后继widget数组中的Name删除
    void sendChangeCableLength(QPointF,QString,double);
    void sendUpdate();//发送更新信号

private slots:
    void getName(QString,int);
    void getUpdate();
    void getLength(QString);
    void getTransNumber(int);
    void getRaise();
    void getChangeFocus(QString);//改变焦点
};

#endif // TRANSWIDGET_H
