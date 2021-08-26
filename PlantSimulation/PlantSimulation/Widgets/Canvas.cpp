#include "Canvas.h"
#include "Widgets/ClockWidget.h"
#include "Widgets/SourceWidget.h"
#include "Widgets/StationWidget.h"
#include "Widgets/PointWidget.h"
#include "Widgets/DrainWidget.h"
#include "Widgets/TransWidget.h"
#include "Widgets/CableLine.h"
#include "Widgets/CableCanvas.h"
#include <QPixmap>
#include <QPainter>
#include <QDebug>

bool Canvas::PressState=false;
bool Canvas::widgetPressState=false;
bool Canvas::createPoint1=false;
bool Canvas::createPoint2=false;
bool Canvas::createCable=false;
double Canvas::Pi=3.14159;
int Canvas::count=0;
//int Canvas::stationNum=1;
//int Canvas::sourceNum=1;
//int Canvas::drainNum=1;

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    clockWidget=new ClockWidget(this);
    connect(this,SIGNAL(sendRaise()),clockWidget,SLOT(getRaise()));
}

void Canvas::getCreateSource()
{
    SourceWidget *sourceWidget=new SourceWidget(this);
    sourceWidget->show();
    connect(sourceWidget,SIGNAL(sendFocus(bool,QString)),this,SLOT(getWidgetPressState(bool,QString)));
    connect(sourceWidget,SIGNAL(sendLinkPoint(QPointF,QString,int,double)),this,SLOT(getLinkPoint(QPointF,QString,int,double)));
    connect(sourceWidget,SIGNAL(sendMoveLinkPoint(QPointF,QString,int,double)),this,SLOT(getMoveLinkPoint(QPointF,QString,int,double)));
    connect(this,SIGNAL(sendCancleFocus(QString)),sourceWidget,SLOT(getChangeFocus(QString)));
    connect(this,SIGNAL(sendRaise()),sourceWidget,SLOT(getRaise()));
    connect(sourceWidget->sourceWindow,SIGNAL(sendWorkTime(QString,QVector<int>)),
            clockWidget->clockWindow->clock,SLOT(getWorkTime(QString,QVector<int>)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendStartSimulation(QString)),sourceWidget,SLOT(getStartSimulation(QString)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendEndSimulation(QString)),sourceWidget,SLOT(getEndSimulation(QString)));
    connect(this,SIGNAL(sendSubsequent(QString,QString)),sourceWidget,SLOT(getSubsequent(QString,QString)));
    connect(this,SIGNAL(sendSubStartSimulation(QString)),sourceWidget,SLOT(getSubStartSimulation(QString)));
    connect(this,SIGNAL(sendSubEndSimulation(QString)),sourceWidget,SLOT(getSubEndSimulation(QString)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendWorkStart(int,QString)),sourceWidget,SLOT(getSourceWork(int,QString)));
    connect(sourceWidget,SIGNAL(sendCargo(QString)),this,SLOT(getCargo(QString)));
    connect(this,SIGNAL(sendWorkState(QString,int)),sourceWidget,SLOT(getWorkState(QString,int)));
    connect(this,SIGNAL(sendDeleteWidget(QString)),sourceWidget,SLOT(getDeleteWidget(QString)));
    connect(sourceWidget,SIGNAL(sendDeleteWidget(QString)),clockWidget->clockWindow->clock,SLOT(getDeleteWidget(QString)));
    connect(clockWidget->clockWindow,SIGNAL(sendSpeedUp()),sourceWidget,SLOT(getSpeedUp()));
    connect(clockWidget->clockWindow,SIGNAL(sendSpeedDown()),sourceWidget,SLOT(getSpeedDown()));
    connect(clockWidget->clockWindow,SIGNAL(sendTimerRemake()),sourceWidget,SLOT(getTimerRemake()));
}

void Canvas::getCreateStation()
{
    StationWidget *stationWidget=new StationWidget(this);
    stationWidget->show();
    connect(stationWidget,SIGNAL(sendFocus(bool,QString)),this,SLOT(getWidgetPressState(bool,QString)));
    connect(stationWidget,SIGNAL(sendLinkPoint(QPointF,QString,int,double)),this,SLOT(getLinkPoint(QPointF,QString,int,double)));
    connect(stationWidget,SIGNAL(sendMoveLinkPoint(QPointF,QString,int,double)),this,SLOT(getMoveLinkPoint(QPointF,QString,int,double)));
    connect(this,SIGNAL(sendCancleFocus(QString)),stationWidget,SLOT(getChangeFocus(QString)));
    connect(this,SIGNAL(sendRaise()),stationWidget,SLOT(getRaise()));
    connect(stationWidget->stationWindow,SIGNAL(sendWorkTime(QString,QVector<int>)),
            clockWidget->clockWindow->clock,SLOT(getWorkTime(QString,QVector<int>)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendStartSimulation(QString)),stationWidget,SLOT(getStartSimulation(QString)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendEndSimulation(QString)),stationWidget,SLOT(getEndSimulation(QString)));
    connect(this,SIGNAL(sendSubsequent(QString,QString)),stationWidget,SLOT(getSubsequent(QString,QString)));
    connect(stationWidget,SIGNAL(sendStartSimulation(QString)),this,SLOT(getStartSimulation(QString)));
    connect(stationWidget,SIGNAL(sendEndSimulation(QString)),this,SLOT(getEndSimulation(QString)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendWorkStart(int,QString)),stationWidget,SLOT(getStationWork(int,QString)));   
    connect(stationWidget,SIGNAL(sendWorkState(QString,int)),this,SLOT(getWorkState(QString,int)));
    connect(this,SIGNAL(sendCargo(QString)),stationWidget,SLOT(getCargo(QString)));
    connect(this,SIGNAL(sendSubStartSimulation(QString)),stationWidget,SLOT(getSubStartSimulation(QString)));
    connect(this,SIGNAL(sendSubEndSimulation(QString)),stationWidget,SLOT(getSubEndSimulation(QString)));
    connect(stationWidget,SIGNAL(sendCargo(QString)),this,SLOT(getCargo(QString)));
    connect(this,SIGNAL(sendWorkState(QString,int)),stationWidget,SLOT(getWorkState(QString,int)));
    connect(stationWidget,SIGNAL(sendDeleteWidget(QString)),this,SLOT(getDeleteWidget(QString)));
    connect(stationWidget,SIGNAL(sendDeleteWidget(QString)),clockWidget->clockWindow->clock,SLOT(getDeleteWidget(QString)));
    connect(clockWidget->clockWindow,SIGNAL(sendSpeedUp()),stationWidget,SLOT(getSpeedUp()));
    connect(clockWidget->clockWindow,SIGNAL(sendSpeedDown()),stationWidget,SLOT(getSpeedDown()));
    connect(clockWidget->clockWindow,SIGNAL(sendTimerRemake()),stationWidget,SLOT(getTimerRemake()));

}

void Canvas::getCreateDrain()
{
    DrainWidget *drainWidget=new DrainWidget(this);
    drainWidget->show();
    connect(drainWidget,SIGNAL(sendFocus(bool,QString)),this,SLOT(getWidgetPressState(bool,QString)));
    connect(drainWidget,SIGNAL(sendLinkPoint(QPointF,QString,int,double)),this,SLOT(getLinkPoint(QPointF,QString,int,double)));
    connect(drainWidget,SIGNAL(sendMoveLinkPoint(QPointF,QString,int,double)),this,SLOT(getMoveLinkPoint(QPointF,QString,int,double)));
    connect(this,SIGNAL(sendCancleFocus(QString)),drainWidget,SLOT(getChangeFocus(QString)));
    connect(this,SIGNAL(sendRaise()),drainWidget,SLOT(getRaise()));
    connect(drainWidget->drainWindow,SIGNAL(sendWorkTime(QString,QVector<int>)),
            clockWidget->clockWindow->clock,SLOT(getWorkTime(QString,QVector<int>)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendStartSimulation(QString)),drainWidget,SLOT(getStartSimulation(QString)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendEndSimulation(QString)),drainWidget,SLOT(getEndSimulation(QString)));
    connect(drainWidget,SIGNAL(sendStartSimulation(QString)),this,SLOT(getStartSimulation(QString)));
    connect(drainWidget,SIGNAL(sendEndSimulation(QString)),this,SLOT(getEndSimulation(QString)));
    connect(clockWidget->clockWindow->clock,SIGNAL(sendWorkStart(int,QString)),drainWidget,SLOT(getDrainWork(int,QString)));
    connect(this,SIGNAL(sendCargo(QString)),drainWidget,SLOT(getCargo(QString)));
    connect(drainWidget,SIGNAL(sendWorkState(QString,int)),this,SLOT(getWorkState(QString,int)));
    connect(drainWidget,SIGNAL(sendDeleteWidget(QString)),clockWidget->clockWindow->clock,SLOT(getDeleteWidget(QString)));
    connect(clockWidget->clockWindow,SIGNAL(sendSpeedUp()),drainWidget,SLOT(getSpeedUp()));
    connect(clockWidget->clockWindow,SIGNAL(sendSpeedDown()),drainWidget,SLOT(getSpeedDown()));
    connect(clockWidget->clockWindow,SIGNAL(sendTimerRemake()),drainWidget,SLOT(getTimerRemake()));
}

void Canvas::getCreateTrans()
{
    TransWidget *transWidget=new TransWidget(this);
    transWidget->show();
    connect(transWidget,SIGNAL(sendFocus(bool,QString)),this,SLOT(getWidgetPressState(bool,QString)));
    connect(transWidget,SIGNAL(sendLinkPoint(QPointF,QString,int,double)),this,SLOT(getLinkPoint(QPointF,QString,int,double)));
    connect(transWidget,SIGNAL(sendMoveLinkPoint(QPointF,QString,int,double)),this,SLOT(getMoveLinkPoint(QPointF,QString,int,double)));
    connect(this,SIGNAL(sendRaise()),transWidget,SLOT(getRaise()));
    connect(transWidget,SIGNAL(sendChangeCableLength(QPointF,QString,double)),this,SLOT(getChangeCableLength(QPointF,QString,double)));
    connect(this,SIGNAL(sendCancleFocus(QString)),transWidget,SLOT(getChangeFocus(QString)));
}

void Canvas::getCreateCable()
{
    CableLine *cableLine=new CableLine(point1,point2,point1Name,point2Name,point1Num,point2Num,point1Length,point2Length,this);
    connect(this,SIGNAL(sendMoveLinkPoint(QPointF,QString,int,double)),cableLine,SLOT(getMoveLinkPoint(QPointF,QString,int,double)));
    this->raise();
    emit sendRaise();
    cableLine->show();
    connect(cableLine,SIGNAL(sendFocus(bool,QString)),this,SLOT(getWidgetPressState(bool,QString)));
    connect(cableLine,SIGNAL(sendLinkPoint(QPointF,QString,int,double)),this,SLOT(getLinkPoint(QPointF,QString,int,double)));
    connect(cableLine,SIGNAL(sendMoveLinkPoint(QPointF,QString,int,double)),this,SLOT(getMoveLinkPoint(QPointF,QString,int,double)));
    connect(this,SIGNAL(sendChangeCableLength(QPointF,QString,double)),cableLine,SLOT(getChangeCableLength(QPointF,QString,double)));
}

void Canvas::getTwoPoint()
{
    createPoint1=true;
    createPoint2=true;
}

void Canvas::getLinkPoint(QPointF _linkPoint,QString _name,int _pointNum,double _widgetLength)
{
    if(createPoint1==true)
    {
        createPoint1=false;
        point1=_linkPoint;
        point1Name=_name;
        cablePoint[point1Name]=point1;//存储Point1的名字和坐标
        point1Num=_pointNum;
        point1Length=_widgetLength;
//        qDebug()<<"point1:"<<_pointNum;
//        qDebug()<<"point1:"<<_name;
    }
    else if(createPoint2==true)
    {
        createPoint2=false;
        point2Name=_name;
        point2=_linkPoint;
        cablePoint[point2Name]=point2;//存储Point2的名字和坐标
        point2Num=_pointNum;
        point2Length=_widgetLength;
//        qDebug()<<"point2:"<<point2Name;
        cablePointName[point1Name].push_back(point2Name);//Point1作为前驱点，其中一个后继点为name=point2Name的widget提供
        emit sendSubsequent(point1Name,point2Name);
//        qDebug()<<cablePointName;
//        qDebug()<<cablePoint;
        getCreateCable();
    }
}


/*移动控件即移动Point，此时需要考虑此Point是前驱点还是后继点，
 * 前驱点的判断方法是：calbePointName.size()!=0
 * 如果size==0,该点不存在后继点，即该点不是前驱点
 *
 * 如果cablePointName.size()==empty()&&cablePoint[Point.name]!=""
 * 即该点不是前驱点且该点的名字和坐标被存储，则该点是后继点
 */
void Canvas::getMoveLinkPoint(QPointF _moveLinkPoint,QString _name,int _pointNum,double _widgetLength)
{
    //该点是前驱点,修改该点的坐标
    if(!cablePointName[_name].empty())
    {
        cablePoint[_name]=_moveLinkPoint;
        emit sendMoveLinkPoint(_moveLinkPoint,_name,_pointNum,_widgetLength);
    }
    //该点不是前驱点
    else
    {
        //该点是后继点，修改该点的坐标
        if(cablePoint[_name]!=QPointF(-1,-1))
        {
            cablePoint[_name]=_moveLinkPoint;
            emit sendMoveLinkPoint(_moveLinkPoint,_name,_pointNum,_widgetLength);
        }
    }
}

//发送鼠标当前点击位置
void Canvas::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {

    }
}

//改变当前焦点
void Canvas::getWidgetPressState(bool _pressState,QString _name)
{
    //当前没有widget被选中，将该widget选中
    if(widgetPressState==false&&_pressState==true)
    {
        widgetPressState=_pressState;//当前有widget被选中
        pressedWidget=_name;//被选中的widget是_name
//        qDebug()<<"1"<<pressedWidget;
    }
    //已经有widget被选中，重新选择聚焦目标，向原有widget发送取消聚焦信号
    else if(widgetPressState==true&&_pressState==true)
    {
        if(_name!=pressedWidget)
        {
            emit sendCancleFocus(pressedWidget);//给原先选中的widget发送取消聚焦信号
            pressedWidget=_name;//将当前选中的widget名赋值给pressWidget
//            qDebug()<<"2"<<pressedWidget;
        }
    }
    //当前widegt被选中，取消选中该widget
    else if(widgetPressState==true&&_pressState==false)
    {
        widgetPressState=_pressState;//当前没有widget被选中
        emit sendCancleFocus(pressedWidget);//发送取消聚焦信号
//        qDebug()<<"3"<<pressedWidget;
        pressedWidget.clear();//当前没有widget被选中
    }
}

void Canvas::getChangeCableLength(QPointF _linkpoint1,QString _widgetCode,double _widgetLength)
{
    emit sendChangeCableLength(_linkpoint1,_widgetCode,_widgetLength);
}

void Canvas::getStartSimulation(QString _name)
{
    emit sendSubStartSimulation(_name);
}

void Canvas::getEndSimulation(QString _name)
{
    emit sendSubEndSimulation(_name);
}

void Canvas::getCargo(QString _name)
{
    emit sendCargo(_name);
}

void Canvas::getWorkState(QString _name,int _workState)
{
//    qDebug()<<"canvas"<<_name<<_workState;
    emit sendWorkState(_name,_workState);
}

void Canvas::getDeleteWidget(QString _name)
{
    emit sendDeleteWidget(_name);
}

void Canvas::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(1964,1200);
    pixmap.fill(Qt::white);
    QPainter p(&pixmap);
    p.setPen(QPen(Qt::black,2));
    for(int i=1;i<49;i++)
    {
        for(int j=1;j<29;j++)
        {
            p.drawPoint(QPoint(40*i,40*j));
        }
    }

    p.end();
//    this->resize(1000,600);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);
}
