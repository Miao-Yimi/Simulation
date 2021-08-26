#ifndef CABLELINE_H
#define CABLELINE_H


#include "Widgets/PointWidget.h"
#include <QWidget>

class CableLine : public QWidget
{
    Q_OBJECT
public:
    explicit CableLine(QPointF, QPointF, QString, QString,int,int,double,double,QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *ev);//选中widget，使用delete删除对象
    QPointF linkPoint1;

private:
    int A1X,A1Y;
    int A2X,A2Y;
    int PressX,PressY;
    int CurrentX,CurrentY;
    int LeftX,LeftY;

    QString name;//控件名字

    static bool pressState;//控件按压状态，全局变量
//    static bool enterState;//控件进入状态
    int pointNum;

    QPointF point1,point2,pressPoint1,pressPoint2;
    QString point1Name,point2Name,pressPoint1Name,pressPoint2Name;
    int point1Num,point2Num,pressPoint1Num,pressPoint2Num;
    double pressPoint1Length,pressPoint2Length;
    static double Pi;
    bool updateFlag;

signals:
    void sendWindowHide();
    void sendFocus(bool,QString);//发送widget被选中、聚焦的信号
    void sendLinkPoint(QPointF,QString,int,double);
    void sendMoveLinkPoint(QPointF,QString,int,double);

private slots:
//    void getPoint1(QPointF);//得到当前点的坐标
//    void getPoint2(QPointF);//得到当前点的坐标
    void getMoveLinkPoint(QPointF,QString,int,double);
    void getChangeFocus(QString);//改变焦点
    void getChangeCableLength(QPointF,QString,double);
    void getUpdate();
};

#endif // CABLELINE_H
