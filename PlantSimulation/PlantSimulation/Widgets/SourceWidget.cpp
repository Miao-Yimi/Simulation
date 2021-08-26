#include "SourceWidget.h"
#include "WidgetWindows/SourceWindow.h"
#include "Widgets/FloatWindow.h"
#include "Widgets/PartWidget.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QTimer>

int SourceWidget::sourceNum=1;

SourceWidget::SourceWidget(QWidget *parent) : QWidget(parent)
{
    pressState=false;
    enterState=false;
    pointNum=1;
    sourceLong=90;
    workState=0;//Source处于空闲待机状态
    workStateString="Waiting";//处于等待作业状态
    simulationState=false;//Source不处于仿真状态
    workStateNum=0;//未接收到开始作业信号
    cargo=100;
    runFlag1=0;
    runFlag3=0;

    A2X=300;
    A2Y=200;
    A1X=this->x();
    A1Y=this->y();

//    name="Source";
    getSourceNumber(sourceNum);

    //创建sourceWindow窗口
    sourceWindow=new SourceWindow;
    sourceWindow->hide();//窗口处于隐藏状态
    sourceWindow->setFixedSize(800,580);


    //创建状态悬浮窗口
    sourceWorkState=new FloatWindow(this);
    sourceWorkState->hide();

    this->setMouseTracking(true);//开启跟踪鼠标功能

    linkPoint1=QPointF(A2X+90,A2Y+65);

    //改变Source name
    connect(sourceWindow->textOption,SIGNAL(sendName(QString,int)),this,SLOT(getName(QString,int)));
    connect(sourceWindow->textOption,SIGNAL(sendUpdate()),this,SLOT(getUpdate()));
    connect(sourceWindow->sourceTab->sourceFrom1->processing,SIGNAL(sendTimeInterval(int)),this,SLOT(getTimeInterval(int)));

    connect(this,SIGNAL(sendWindowShow()),this,SLOT(getWindowShow()));
    connect(this,SIGNAL(sendWindowHide()),this,SLOT(getWindowHide()));
}



void SourceWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        pressState=true;
        this->setFocus();
        emit sendFocus(pressState,sourceCode);//发送widget已经被选中的信号,需要将其他焦点屏蔽

        PressX=ev->globalX();//鼠标相对于桌面显示器的位置
        PressY=ev->globalY();

        A1X=this->x();//widget左上角相对于程序窗口的位置
        A1Y=this->y();

        linkPoint1=QPointF(A1X+90,A1Y+65);
        emit sendLinkPoint(linkPoint1,sourceCode,pointNum,sourceLong);
    }
    update();
}

void SourceWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        CurrentX=ev->globalX();
        CurrentY=ev->globalY();

        A2X=A1X+CurrentX-PressX;
        A2Y=A1Y+CurrentY-PressY;

        linkPoint1=QPointF(A2X+90,A2Y+65);
        emit sendMoveLinkPoint(linkPoint1,sourceCode,pointNum,sourceLong);

        update();
    }
}

void SourceWidget::mouseReleaseEvent(QMouseEvent *ev)
{
//    pressState=false;
    update();
}

void SourceWidget::mouseDoubleClickEvent(QMouseEvent *ev)
{
    sourceWindow->show();
    update();
}

void SourceWidget::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_Delete)
    {
//        qDebug()<<"delete";
        if(this->hasFocus()==true){
            emit sendFocus(pressState,sourceCode);
            pressState=false;
            emit sendDeleteWidget(sourceCode);//发送该控件被删除的信号
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
        emit sendFocus(pressState,sourceCode);
    }
}

void SourceWidget::getName(QString _name,int _fontwidth)
{
    name=_name;
    fontDis=(90-_fontwidth)/2;
}

void SourceWidget::getUpdate()
{
    update();
}

void SourceWidget::enterEvent(QEvent *ev)
{
//    qDebug()<<"enter";
    enterState=true;
    emit sendWindowShow();
}

void SourceWidget::leaveEvent(QEvent *ev)
{
//    qDebug()<<"leave";
    enterState=false;
    emit sendWindowHide();
}

//始终显示悬浮框在widget上方，widget距窗口初始距离x=700,y=434
void SourceWidget::getWindowShow()
{
    //转换全局坐标
    leftPoint=QWidget::mapToGlobal(this->pos());
//    qDebug()<<"pos:"<<this->pos()<<"leftPoint:"<<leftPoint;
    LeftX=500-this->pos().x();
    LeftY=200-this->pos().y();
//    qDebug()<<LeftX<<leftPoint.x()-530+LeftX;

    sourceWorkState->setGeometry(leftPoint.x()-530+LeftX,leftPoint.y()-280+LeftY,150,65);
    sourceWorkState->show();

}

void SourceWidget::getWindowHide()
{
//    qDebug()<<"hide";
    sourceWorkState->hide();
}

void SourceWidget::getRaise()
{
    this->raise();
}

void SourceWidget::getSpeedUp()
{
    tempTimeInterval=tempTimeInterval/2;
//    qDebug()<<"source:"<<timeInterval;
}

void SourceWidget::getSpeedDown()
{
    tempTimeInterval=tempTimeInterval*2;
//    qDebug()<<"source:"<<timeInterval;
}

void SourceWidget::getTimerRemake()
{

    workState=0;//将当前widget的状态置为0，处于待机状态
    workStateString="Standby";
    sourceWorkState->getWorkState(workStateString);
    runFlag1=0;
    runFlag3=0;
    for(int i=0;i<subsequentWidget.size();i++)
    {
        subWorkState[subsequentWidget.at(i)]=0;//将当前widget的后继widget状态置为0，处于待机状态

        subSimulationState[subsequentWidget.at(i)]=0;//将当前widget的后继widget仿真状态置为0，退出仿真状态
    }
}

void SourceWidget::getChangeFocus(QString _name)
{
    if(_name==sourceCode&&pressState==true)
    {
        pressState=false;
//        屏蔽焦点
        this->setFocusPolicy(Qt::NoFocus);
        update();
    }
}

void SourceWidget::getSourceNumber(int _sourceNum)
{
    name="Source"+QString::number(_sourceNum);
    sourceCode="Source"+QString::number(_sourceNum);
    fontDis=(90-fontMetrics().width(name))/2;
//    qDebug()<<name;
}

void SourceWidget::getStartSimulation(QString _name)
{
    if(_name==sourceCode)
    {
        simulationState=true;//进入仿真状态
        update();
//        qDebug()<<"start"<<name;
    }
}

void SourceWidget::getEndSimulation(QString _name)
{
    if(_name==sourceCode)
    {
        simulationState=false;//结束仿真状态
        update();
//        qDebug()<<"end"<<name;
    }
}

void SourceWidget::getSubsequent(QString _point1Name,QString _point2Name)
{
    /* 如果是前驱节点，存储后继节点的相关信息：name,simulationState,workState
     * 此处首先认为是初始化逻辑的过程，将simulationState,workState置为false
     * 后续开发过程中，如果要求在控件运行过程中也可以连线再做修改
     */
    if(_point1Name==sourceCode)
    {
//        未找到name=_point2Name的widget
        if(std::find(subsequentWidget.begin(),subsequentWidget.end(),_point2Name)==subsequentWidget.end())
        {
            subsequentWidget.push_back(_point2Name);
            subSimulationState[_point2Name]=false;
            subWorkState[_point2Name]=false;
            qDebug()<<sourceCode<<"subsequentWidget:"<<subsequentWidget;
        }
    }
}

void SourceWidget::getDeleteWidget(QString _name)
{
    for(int i=0;i<subsequentWidget.size();i++)
    {
        if(subsequentWidget[i]==_name)
        {
            subsequentWidget.erase(subsequentWidget.begin()+i);
        }
    }
    qDebug()<<sourceCode<<"subsequentWidget:"<<subsequentWidget;
}

void SourceWidget::getSubStartSimulation(QString _name)
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

void SourceWidget::getSubEndSimulation(QString _name)
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

/*Source接到时钟发送的开始作业信号后，不一定能够立刻开始作业，首先对时钟发送的开始作业信号进行存储
 * 只有当前Source的workState==0&&simulationState=true
 * 并且其后继widget中存在simulationState=true且workState=0的widget，Source才能够发送货物
 * 如果Source可以发送货物，发送货物，并且在timeInterval内Source处于工作状态，workState=1
 * 此时，启动一个定时器，timInterval后，自动跳出作业状态
 */
void SourceWidget::getSourceWork(int _currentTimeNum,QString _name)
{
    //时钟发送的开始作业信号是Source的,且Source处于空闲待机状态

    if(_name==sourceCode)
    {
//        qDebug()<<_currentTimeNum<<_name;
        workStateNum++;//接收到时钟发送的开始作业信号      
        if(runFlag3==0)
        {
//            qDebug()<<"source1:接收时钟信号";
            runFlag1=1;
            sendCargoToSub();
        }
    }
}

void SourceWidget::sendCargoToSub()
{
    bool blockedFlag=false;//source后所有后继widget均处于阻塞状态
    for(auto it=subSimulationState.begin();it!=subSimulationState.end();it++)
    {
//        qDebug()<<it.key()<<subWorkState[it.key()];
        if(it.value()==true&&subWorkState[it.key()]==0)//存在state=waiting 的后继widget
        {     
            if(cargo>0)
            {
                cargo--;
                emit sendCargo(it.key());

                workStateString="Working";
                sourceWorkState->getWorkState(workStateString);
                workState=1;//Source工作状态改为：正在工作
                update();

                //定义一个定时器，当经过timeInterval后，即完成发送货物后，启动定时器，将Source工作状态调整为workState=0
                QTimer *pTimer=new QTimer();
                pTimer->setSingleShot(true);
                //Source瞬时发送货物，发送的时间间隔是timeInterval秒
                pTimer->start(double(tempTimeInterval*0.1)*1000);
                connect(pTimer,SIGNAL(timeout()),this,SLOT(changeWorkState()));

            }
            blockedFlag=true;
            break;
        }
    }
    if(blockedFlag==false)
    {
        workState=2;
        workStateString="Blocked";
    }
    else
    {
        workState=0;
        workStateString="Waiting";
    }
    update();
    sourceWorkState->getWorkState(workStateString);
}


/*widget处于什么工作状态与其后继widget有关
 * 例如，当前widget处理完成后，当时间<timeInterval，widget处于等待状态，处于货物发送后的缓冲时间，state=waiting
 * 当时间>timeInterval，widget处于阻塞状态，此时widget已经可以发送货物，但由于后继widget不是空闲状态，state=blocked
*/
void SourceWidget::changeWorkState()
{
    workState=0;
    update();
    workStateString="Waiting";
    sourceWorkState->getWorkState(workStateString);
    QTimer *pTimer=new QTimer();
    pTimer->setSingleShot(true);
    //Source瞬时发送货物，发送的时间间隔是timeInterval秒
    pTimer->start(double(tempTimeInterval*0.9)*1000);
    connect(pTimer,SIGNAL(timeout()),this,SLOT(changeWorkState2()));
}

void SourceWidget::changeWorkState2()
{
    bool blockedFlag=false;//source后所有后继widget均处于阻塞状态
    for(auto it=subSimulationState.begin();it!=subSimulationState.end();it++)
    {
//        qDebug()<<it.key()<<subWorkState[it.key()];
        if(it.value()==true&&subWorkState[it.key()]==0)//存在state=waiting 的后继widget
        {
            blockedFlag=true;
            break;
        }
    }
    if(blockedFlag==false)
    {
        workState=2;
        workStateString="Blocked";
    }
    else
    {
        workState=0;
        workStateString="Waiting";
    }
    update();
    sourceWorkState->getWorkState(workStateString);
}

void SourceWidget::getTimeInterval(int _timeInterval)
{
    timeInterval=_timeInterval;
    tempTimeInterval=timeInterval;
}

/*当后继的widget完成加工，此时widget处于货物发送后的缓冲时间，state=waiting
*/
void SourceWidget::getWorkState(QString _name,int _workState)
{
    for(auto it=subWorkState.begin();it!=subWorkState.end();it++)
    {
        if(it.key()==_name)
        {
//            qDebug()<<"change:"<<_name<<_workState;
            it.value()=_workState;
//            qDebug()<<"it.key:"<<it.key()<<it.value();
            if(_workState==0)
            {
//                qDebug()<<"source1:接收后继完成信号";
                runFlag3=1;
                sendCargoToSub(); 
            }
            break;
        }
    }
//    qDebug()<<subWorkState;
}


void SourceWidget::paintEvent(QPaintEvent *ev)
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
    p.drawPixmap(QPoint(0,20),QPixmap("../Pictures/source.jpg"));
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

