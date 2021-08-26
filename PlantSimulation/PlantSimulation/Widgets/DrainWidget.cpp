#include "DrainWidget.h"
#include "WidgetWindows/DrainWindow.h"
#include "Widgets/FloatWindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QTimer>

int DrainWidget::drainNum=1;

DrainWidget::DrainWidget(QWidget *parent) : QWidget(parent)
{
    pressState=false;
    enterState=false;
    pointNum=1;
    drainLong=90;
    workState=0;//Source处于空闲待机状态
    workStateString="Waiting";//处于等待作业状态
    simulationState=false;//Source不处于仿真状态
    workStateNum=0;//未接收到开始作业信号
    cargo=false;
    runFlag1=0;
    runFlag2=0;

    A2X=700;
    A2Y=200;
    A1X=this->x();
    A1Y=this->y();

//    name="Drain";
//    fontDis=22;
    getDrainNumber(drainNum);

    //创建drainWindow窗口
    drainWindow=new DrainWindow;
    drainWindow->hide();//窗口处于隐藏状态
    drainWindow->setFixedSize(800,580);

    //创建状态悬浮窗口
    drainWorkState=new FloatWindow(this);
    drainWorkState->hide();

    this->setMouseTracking(true);//开启跟踪鼠标功能

    linkPoint1=QPointF(A2X+0,A2Y+65);


    //改变drain name
    connect(drainWindow->textOption,SIGNAL(sendName(QString,int)),this,SLOT(getName(QString,int)));
    connect(drainWindow->textOption,SIGNAL(sendUpdate()),this,SLOT(getUpdate()));
    connect(drainWindow->drainTab->drainFrom1->processing,SIGNAL(sendTimeInterval(int)),this,SLOT(getTimeInterval(int)));

    connect(this,SIGNAL(sendWindowShow()),this,SLOT(getWindowShow()));
    connect(this,SIGNAL(sendWindowHide()),this,SLOT(getWindowHide()));

}

void DrainWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        pressState=true;
        this->setFocus();
        emit sendFocus(pressState,drainCode);//发送widget已经被选中的信号,需要将其他焦点屏蔽


        PressX=ev->globalX();//鼠标相对于桌面显示器的位置
        PressY=ev->globalY();

        A1X=this->x();//widget左上角相对于程序窗口的位置
        A1Y=this->y();

        emit sendWindowHide();

        linkPoint1=QPointF(A1X+0,A1Y+65);
        emit sendLinkPoint(linkPoint1,drainCode,pointNum,drainLong);

    }
    update();

}

void DrainWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        CurrentX=ev->globalX();
        CurrentY=ev->globalY();

        A2X=A1X+CurrentX-PressX;
        A2Y=A1Y+CurrentY-PressY;

        emit sendWindowHide();

        linkPoint1=QPointF(A2X+0,A2Y+65);
        emit sendMoveLinkPoint(linkPoint1,drainCode,pointNum,drainLong);
        update();
    }
}

void DrainWidget::mouseReleaseEvent(QMouseEvent *ev)
{
//    pressState=false;
    update();
}

void DrainWidget::mouseDoubleClickEvent(QMouseEvent *ev)
{
    drainWindow->show();
    update();
}

void DrainWidget::keyPressEvent(QKeyEvent *ev)
{

    if(ev->key()==Qt::Key_Delete)
    {
//        qDebug()<<this->hasFocus();//判断焦点是否在widget上
//        发送widget取消选中的信号，但此时是因为widget被删除
        if(this->hasFocus()==true){
            emit sendFocus(pressState,drainCode);
            pressState=false;
            emit sendDeleteWidget(drainCode);//发送该控件被删除的信号
            delete this;
        }
    }
    else if(ev->key()==Qt::Key_Escape)
    {
//        widget通过esc取消聚焦
//        qDebug()<<"enter";
        pressState=false;
        this->setFocusPolicy(Qt::NoFocus);
        update();
        emit sendFocus(pressState,drainCode);
    }
}

void DrainWidget::getChangeFocus(QString _name)
{
    if(_name==drainCode&&pressState==true)
    {
        pressState=false;
//        屏蔽焦点
        this->setFocusPolicy(Qt::NoFocus);
        update();
    }
}

void DrainWidget::getName(QString _name,int _fontwidth)
{
    name=_name;
    fontDis=(90-_fontwidth)/2;
}

void DrainWidget::getUpdate()
{
    update();
}

void DrainWidget::enterEvent(QEvent *ev)
{
//    qDebug()<<"enter";
    enterState=true;
    emit sendWindowShow();
}

void DrainWidget::leaveEvent(QEvent *ev)
{
//    qDebug()<<"leave";
    enterState=false;
    emit sendWindowHide();
}

//始终显示悬浮框在widget上方，widget距窗口初始距离x=700,y=434
void DrainWidget::getWindowShow()
{
    //转换全局坐标
    leftPoint=QWidget::mapToGlobal(this->pos());
//    qDebug()<<"pos:"<<this->pos()<<"leftPoint:"<<leftPoint;
    LeftX=500-this->pos().x();
    LeftY=200-this->pos().y();
//    qDebug()<<LeftX<<leftPoint.x()-530+LeftX;

    drainWorkState->setGeometry(leftPoint.x()-530+LeftX,leftPoint.y()-280+LeftY,150,65);
    drainWorkState->show();

}

void DrainWidget::getWindowHide()
{
//    qDebug()<<"hide";
    drainWorkState->hide();
}

void DrainWidget::getRaise()
{
    this->raise();
}

void DrainWidget::getSpeedUp()
{
    tempTimeInterval=tempTimeInterval/2;
//    qDebug()<<"drain:"<<timeInterval;
}

void DrainWidget::getSpeedDown()
{
    tempTimeInterval=tempTimeInterval*2;
//    qDebug()<<"source:"<<timeInterval;
}

void DrainWidget::getTimerRemake()
{
    workState=0;//将当前widget的状态置为0，处于待机状态
    workStateString="Standby";
    drainWorkState->getWorkState(workStateString);
    runFlag1=0;
    runFlag2=0;
}

void DrainWidget::getDrainNumber(int _drainNum)
{
    name="Drain"+QString::number(_drainNum);
    drainCode="Drain"+QString::number(_drainNum);
    fontDis=(90-fontMetrics().width(name))/2;
//    qDebug()<<name;
}

void DrainWidget::getStartSimulation(QString _name)
{
    if(_name==drainCode)
    {
        simulationState=true;//进入仿真状态
        update();
//        qDebug()<<"start"<<name;
        emit sendStartSimulation(drainCode);
    }
}

void DrainWidget::getEndSimulation(QString _name)
{
    if(_name==drainCode)
    {
        simulationState=false;//结束仿真状态
        update();
//        qDebug()<<"end"<<name;
        emit sendEndSimulation(drainCode);
    }
}

void DrainWidget::getCargo(QString _name)
{
    if(_name==drainCode&&workState==0)
    {
        cargo=true;//Station接收到货物
//        qDebug()<<"drain2:接收货物信号";
        runFlag2=1;
        drainWork();
//        qDebug()<<"getCargo";
    }
}

void DrainWidget::getDrainWork(int _currentTimeNum,QString _name)
{
    if(_name==drainCode)
    {
//        qDebug()<<_currentTimeNum<<_name;
        workStateNum++;//接收到时钟发送的开始作业信号

        if(runFlag2==0)
        {
//            qDebug()<<"drain1:接收时钟信号";
            runFlag1=1;
            drainWork();
        }
    }
}

void DrainWidget::drainWork()
{
        if(workStateNum>0&&cargo==true)
        {
            workState=1;
            emit sendWorkState(drainCode,workState);
            update();

            workStateString="Working";
            drainWorkState->getWorkState(workStateString);

            cargo=false;
            workStateNum--;
            QTimer *pTimer=new QTimer();
            pTimer->setSingleShot(true);
            pTimer->start(tempTimeInterval*1000);
            connect(pTimer,SIGNAL(timeout()),this,SLOT(changeWorkState()));
        }
}

void DrainWidget::changeWorkState()
{
    workState=0;
    workStateString="Waiting";
    drainWorkState->getWorkState(workStateString);
    emit sendWorkState(drainCode,workState);
    update();
}

void DrainWidget::getTimeInterval(int _timeInterval)
{
    timeInterval=_timeInterval;
    tempTimeInterval=timeInterval;
}

void DrainWidget::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(90,150);//控件图标大小为90*130
    pixmap.fill(Qt::transparent);

    QPainter p(&pixmap);
    if(simulationState==true)
    {
        if(workState==0)
        {
           p.setBrush(Qt::yellow);
        }
        else if(workState==1)
        {
            p.setBrush(Qt::green);
        }
        else if(workState==2)
        {
            p.setBrush(Qt::red);
        }
        p.drawEllipse(35,0,15,15);
    }

    p.drawText(fontDis,130,name);
    p.drawPixmap(QPoint(0,20),QPixmap("../Pictures/drain.jpg"));
    p.setPen(Qt::white);
#if 0
    if(pixmapState==true)
    {
        p.setBrush(QColor(255,218,185));
        p.setPen(Qt::black);
        p.drawRect(36,34,20,20);
    }
#endif
    if(pressState==true)
    {
        p.setBrush(QColor(200,200,200,100));
        p.drawRect(0,20,90,120);
    }

    p.end();
    this->resize(90,150);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);
    this->move(A2X,A2Y);
}


