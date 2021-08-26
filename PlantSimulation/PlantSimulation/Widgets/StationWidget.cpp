#include "StationWidget.h"
#include "WidgetWindows/StationWindow.h"
#include "Widgets/FloatWindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QTimer>

int StationWidget::stationNum=1;

StationWidget::StationWidget(QWidget *parent) : QWidget(parent)
{
    pressState=false;
    enterState=false;
    pointNum=2;
    stationLong=90;
    simulationState=false;
    workState=0;//控件处于空闲待机状态
    workStateString="Waiting";//处于等待作业状态
    cargo=0;//接收货物的状态
    stationcargo=0;
    workStateNum=0;
    runFlag1=0;
    runFlag2=0;
    runFlag3=0;

    A2X=500;
    A2Y=200;
    A1X=this->x();
    A1Y=this->y();

//    name="Station";
//    fontDis=14;
    getStationNumber(stationNum);

    //创建stationWindow窗口
    stationWindow=new StationWindow;
    stationWindow->hide();//窗口处于隐藏状态
    stationWindow->setFixedSize(800,580);

    //创建状态悬浮窗口
    stationWorkState=new FloatWindow(this);
    stationWorkState->hide();

    this->setMouseTracking(true);//开启跟踪鼠标功能

    linkPoint1=QPointF(A2X+45,A2Y+65);


    //改变Station name
    connect(stationWindow->textOption,SIGNAL(sendName(QString,int)),this,SLOT(getName(QString,int)));
    connect(stationWindow->textOption,SIGNAL(sendUpdate()),this,SLOT(getUpdate()));
    connect(stationWindow->stationTab->stationFrom1->processing,SIGNAL(sendTimeInterval(int)),this,SLOT(getTimeInterval(int)));

    connect(this,SIGNAL(sendWindowShow()),this,SLOT(getWindowShow()));
    connect(this,SIGNAL(sendWindowHide()),this,SLOT(getWindowHide()));

}

void StationWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        pressState=true;
        this->setFocus();
        emit sendFocus(pressState,stationCode);//发送widget已经被选中的信号,需要将其他焦点屏蔽

        PressX=ev->globalX();//鼠标相对于桌面显示器的位置
        PressY=ev->globalY();

        A1X=this->x();//widget左上角相对于程序窗口的位置
        A1Y=this->y();

        emit sendWindowHide();

        linkPoint1=QPointF(A1X+45,A1Y+65);
        emit sendLinkPoint(linkPoint1,stationCode,pointNum,stationLong);

    }
    update();

}

void StationWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        CurrentX=ev->globalX();
        CurrentY=ev->globalY();

        A2X=A1X+CurrentX-PressX;
        A2Y=A1Y+CurrentY-PressY;

        emit sendWindowHide();

        linkPoint1=QPointF(A2X+45,A2Y+65);
        emit sendMoveLinkPoint(linkPoint1,stationCode,pointNum,stationLong);
        update();
    }
}

void StationWidget::mouseReleaseEvent(QMouseEvent *ev)
{
//    pressState=false;
    update();
}

void StationWidget::mouseDoubleClickEvent(QMouseEvent *ev)
{
    stationWindow->show();
    update();
}

void StationWidget::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_Delete)
    {
//        qDebug()<<this->hasFocus();//判断焦点是否在widget上
//        发送widget取消选中的信号，但此时是因为widget被删除
        if(this->hasFocus()==true){
            emit sendFocus(pressState,stationCode);
            pressState=false;
            emit sendDeleteWidget(stationCode);//发送该控件被删除的信号
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
        emit sendFocus(pressState,stationCode);
    }
}

void StationWidget::getName(QString _name,int _fontwidth)
{
    name=_name;
    fontDis=(90-_fontwidth)/2;
}

void StationWidget::getUpdate()
{
    update();
}

void StationWidget::enterEvent(QEvent *ev)
{
//    qDebug()<<"enter";
    enterState=true;
    emit sendWindowShow();
}

void StationWidget::leaveEvent(QEvent *ev)
{
//    qDebug()<<"leave";
    enterState=false;
    emit sendWindowHide();
}

//始终显示悬浮框在widget上方，widget距窗口初始距离x=700,y=434
void StationWidget::getWindowShow()
{
    //转换全局坐标
    leftPoint=QWidget::mapToGlobal(this->pos());
//    qDebug()<<"pos:"<<this->pos()<<"leftPoint:"<<leftPoint;
    LeftX=500-this->pos().x();
    LeftY=200-this->pos().y();
//    qDebug()<<LeftX<<leftPoint.x()-530+LeftX;

    stationWorkState->setGeometry(leftPoint.x()-530+LeftX,leftPoint.y()-280+LeftY,150,65);
    stationWorkState->show();

}

void StationWidget::getWindowHide()
{
//    qDebug()<<"hide";
    stationWorkState->hide();
}

//改变焦点

void StationWidget::getChangeFocus(QString _name)
{
    if(_name==stationCode&&pressState==true)
    {
        pressState=false;
//        屏蔽焦点
        this->setFocusPolicy(Qt::NoFocus);
        update();
    }
}

void StationWidget::getRaise()
{
    this->raise();
}

void StationWidget::getSpeedUp()
{
    tempTimeInterval=tempTimeInterval/2;
//    qDebug()<<"station:"<<timeInterval;
}

void StationWidget::getSpeedDown()
{
    tempTimeInterval=tempTimeInterval*2;
//    qDebug()<<"source:"<<timeInterval;
}

void StationWidget::getTimerRemake()
{
    workState=0;//将当前widget的状态置为0，处于待机状态
    workStateString="Standby";
    stationWorkState->getWorkState(workStateString);
    runFlag1=0;
    runFlag2=0;
    runFlag3=0;
    for(int i=0;i<subsequentWidget.size();i++)
    {
        subWorkState[subsequentWidget.at(i)]=0;//将当前widget的后继widget状态置为0，处于待机状态

        subSimulationState[subsequentWidget.at(i)]=0;//将当前widget的后继widget仿真状态置为0，退出仿真状态
    }
}

void StationWidget::getStationNumber(int _stationNum)
{
    name="Station"+QString::number(_stationNum);
    stationCode="Station"+QString::number(_stationNum);
    fontDis=(90-fontMetrics().width(name))/2;
//    qDebug()<<name;
}

void StationWidget::getStartSimulation(QString _name)
{
    if(_name==stationCode)
    {
        simulationState=true;//进入仿真状态
//        qDebug()<<"start"<<name;
        update();
        emit sendStartSimulation(stationCode);
    }
}

void StationWidget::getEndSimulation(QString _name)
{
    if(_name==stationCode)
    {
        simulationState=false;//结束仿真状态
        update();
        emit sendEndSimulation(stationCode);
//        qDebug()<<"end"<<name;
    }
}

void StationWidget::getSubsequent(QString _point1Name,QString _point2Name)
{
    if(_point1Name==stationCode)
    {
//        未找到name=_point2Name的widget
        if(std::find(subsequentWidget.begin(),subsequentWidget.end(),_point2Name)==subsequentWidget.end())
        {
            subsequentWidget.push_back(_point2Name);
            subSimulationState[_point2Name]=false;
            subWorkState[_point2Name]=false;
            qDebug()<<stationCode<<"subsequentWidget:"<<subsequentWidget;
        }
    }
}

void StationWidget::getDeleteWidget(QString _name)
{
    for(int i=0;i<subsequentWidget.size();i++)
    {
        if(subsequentWidget[i]==_name)
        {
            subsequentWidget.erase(subsequentWidget.begin()+i);
        }
    }
    qDebug()<<stationCode<<"subsequentWidget:"<<subsequentWidget;
}

void StationWidget::getSubStartSimulation(QString _name)
{
    for(auto it=subSimulationState.begin();it!=subSimulationState.end();it++)
    {
        if(it.key()==_name)
        {
            it.value()=true;
//            qDebug()<<subSimulationState;
            break;
        }
    }
}

void StationWidget::getSubEndSimulation(QString _name)
{
    for(auto it=subSimulationState.begin();it!=subSimulationState.end();it++)
    {
        if(it.key()==_name)
        {
            it.value()=false;
//            qDebug()<<subSimulationState;
            break;
        }
    }
}

/*当Station从时钟处接收到开始作业信号，Station准备开始工作
 *但由于此时并没有货物发送到该Station，只有当其接收到货物，即cargo=true时，Station
 */
void StationWidget::getStationWork(int _currentTimeNum,QString _name)
{
    //Source给该Station发送了货物，意味着Station原本simulationState=true，workState=0
    if(_name==stationCode)
    {
//        qDebug()<<_currentTimeNum<<_name;
        workStateNum++;

        if(runFlag2==0&&runFlag3==0)
        {
//            qDebug()<<"station1:接收时钟信号";
            runFlag1=1;
            stationWork();
        }
    }
}

void StationWidget::getCargo(QString _name)
{
    if(_name==stationCode&&workState==0)
    {
        cargo++;//Station接收到货物
//        qDebug()<<"station2:接收货物信号";
        runFlag2=1;
        stationWork();
    }
}

void StationWidget::stationWork()
{

    if(cargo>0&&workStateString!="Blocked")
    {
        workState=1;
        emit sendWorkState(stationCode,workState);
        update();
        workStateString="Working";
        stationWorkState->getWorkState(workStateString);
        workStateNum--;
        cargo--;
        stationcargo++;
        QTimer *pTimer=new QTimer();
        pTimer->setSingleShot(true);
        pTimer->start(tempTimeInterval*1000);
        connect(pTimer,SIGNAL(timeout()),this,SLOT(sendCargoToSub()));
    }
}

void StationWidget::getTimeInterval(int _timeInterval)
{
    timeInterval=_timeInterval;
    tempTimeInterval=timeInterval;
//    qDebug()<<name<<timeInterval;
}

void StationWidget::getWorkState(QString _name,int _workState)
{

    for(auto it=subWorkState.begin();it!=subWorkState.end();it++)
    {
        if(it.key()==_name)
        {
            it.value()=_workState;
            /*当后继widget完成作业，处于waiting状态，station的blocked状态需要被解开
             * 此时station中如果存在货物，则直接发送到后继widget中
            */
            if(_workState==0)
            {
//                qDebug()<<"station3:接收后继完成信号";
                runFlag3=1;
                sendCargoToSub();
                break;
            }
        }
    }
 }

//判断是否存在合适的后继widget，使得当前完成加工的货物可以被发送过去
/* Staion在timeInterval时间后完成加工，需要改变其工作状态并将零部件发送到下一个widget中
 * 发送到下一个widget中，则要求其后继widget有进入仿真状态且workState==0
 * 等待接收是等待状态，state=waiting，等待发送是阻塞状态，state=blocked
*/
void StationWidget::sendCargoToSub()
{
    bool flag=false;
    for(auto it=subSimulationState.begin();it!=subSimulationState.end();it++)
    {
        if(it.value()==true&&subWorkState[it.key()]==0&&stationcargo>0)//存在state=waiting 的后继widget
        {
            emit sendCargo(it.key());
            stationcargo--;
            flag=true;
            break;
        }
    }
    if(flag==true)
    {
        workState=0;
        workStateString="Waiting";
    }
    else if(flag==false&&stationcargo>0)
    {
        workState=2;
        workStateString="Blocked";
//        qDebug()<<"station blocked1";
    }
    stationWorkState->getWorkState(workStateString);
    emit sendWorkState(stationCode,workState);
//    qDebug()<<"sendWorkState2";
    update();

    if(runFlag3==1)
    {
        runFlag3=0;
    }
    else if(runFlag2==1)
    {
        runFlag2=0;
    }
    else if(runFlag1==1)
    {
        runFlag1=0;
    }
}


void StationWidget::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(90,150);//控件图标大小为90*130
    pixmap.fill(Qt::transparent);

    QPainter p(&pixmap);

    if(simulationState==true)
    {
        if(workState==0)//处于等待状态
        {
           p.setBrush(Qt::yellow);
        }
        else if(workState==1)//处于工作状态
        {
            p.setBrush(Qt::green);
        }
        else if(workState==2)//处于阻塞状态
        {
            p.setBrush(Qt::red);
        }
        p.drawEllipse(35,0,15,15);
    }

    p.drawText(fontDis,130,name);
    p.drawPixmap(QPoint(0,20),QPixmap("../Pictures/station.jpg"));
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
