#include "Clock.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QPainter>

Clock::Clock(QWidget *parent) : QWidget(parent)
{
    timer=new QTimer(this);
    timerStart=false;

    //输入的字符串
    _startTime="2020-10-21 9:14:30";
    _endTime="";
    _currentTime=_startTime;

    //输入的字符串转换为秒
    currentTimeNum=startTime.fromString(_currentTime,"yyyy-MM-dd hh:mm:ss").toTime_t();
    endTimeNum=endTime.fromString(_endTime,"yyyy-MM-dd hh:mm:ss").toTime_t();

//    qDebug()<<currentTimeNum;
//    qDebug()<<endTimeNum;

    speed=1000;

}

void Clock::getStartTime(QString _str)
{
    _startTime=_str;
//    qDebug()<<"_startTime:"<<_startTime;
    _currentTime=_startTime;
    currentTimeNum=startTime.fromString(_currentTime,"yyyy-MM-dd hh:mm:ss").toTime_t();
//    qDebug()<<"currentTimeNum"<<currentTimeNum;
    update();
}

void Clock::getEndTime(QString _str)
{
    _endTime=_str;
//    qDebug()<<"_endTime:"<<_endTime;
    endTimeNum=endTime.fromString(_endTime,"yyyy-MM-dd hh:mm:ss").toTime_t();
//    qDebug()<<"endTimeNum"<<endTimeNum;
}

//获取某一控件的作业时间
void Clock::getWorkTime(QString _name, QVector<int> _workTime)
{
    int last=_workTime.size();
    workTime=_workTime;

    //存储各控件开始和结束仿真时间
    widgetStartTime[_name]=_workTime.at(0);
    widgetEndTime[_name]=_workTime.at(last-1);
//    qDebug()<<_name<<widgetStartTime[_name]<<widgetEndTime[_name];
    arrangeTime(_name,workTime);
}

void Clock::arrangeTime(QString _name, QVector<int> _workTime)
{
    for(int i=0;i<_workTime.size();i++)
    {
        QVector<QString> vector=timerReceiver[_workTime.at(i)];
        QVector<QString>::const_iterator iter=qFind(vector.begin(),vector.end(),_name);

        if(iter==vector.end())
        {
//            qDebug()<<name;
            timerReceiver[workTime.at(i)].append(_name);
        }
    }
//    qDebug()<<timerReceiver;
}

void Clock::getDeleteWidget(QString _name)
{
    for(auto it=timerReceiver.begin();it!=timerReceiver.end();it++)
    {
        //找到了需要删除的widget时间安排信息，find函数的返回值是地址
        for(int i=0;i<it.value().size();i++)
        {
            if(it.value().at(i)==_name)
            {
                it.value().erase(it.value().begin()+i);
            }
        }
    }
//    qDebug()<<timerReceiver;
}

void Clock::changeCurrentTime()
{
    bool flag=true;
    if(currentTimeNum>endTimeNum||endTimeNum==-1)
    {
        flag=false;
    }
    if(flag==true)
    {
//        qDebug()<<currentTimeNum;

        _currentTime=startTime.fromTime_t(currentTimeNum).toString("yyyy-MM-dd hh:mm:ss");

        //发送控件进入仿真状态信号
        for(auto it=widgetStartTime.begin();it!=widgetStartTime.end();it++)
        {
            if(currentTimeNum==it.value())
            {
//                qDebug()<<it.key();
                emit sendStartSimulation(it.key());
            }
        }
        //发送控件结束仿真状态信号
        for(auto it=widgetEndTime.begin();it!=widgetEndTime.end();it++)
        {
            if(currentTimeNum==it.value())
            {
//                qDebug()<<it.key();
                emit sendEndSimulation(it.key());
            }
        }

        //按控件作业时间向主窗口发送该控件作业开始信号
        if(timerReceiver[currentTimeNum].size()!=0)
        {
//            qDebug()<<currentTimeNum;

            for(int i=0;i<timerReceiver[currentTimeNum].size();i++)
            {
//                qDebug()<<currentTimeNum<<timerReceiver[currentTimeNum].at(i);
                emit sendWorkStart(currentTimeNum,timerReceiver[currentTimeNum].at(i));
            }
#if 0

            while(timerReceiver[currentTimeNum].size()!=0)
            {
//                emit sendWorkStart(timerReceiver[currentTimeNum].at(0));
                timerReceiver[currentTimeNum].pop_front();
                qDebug()<<timerReceiver[currentTimeNum].size()<<timerReceiver[currentTimeNum];
            }
#endif
        }

        connect(timer,SIGNAL(timeout()),this,SLOT(update()));
        ++currentTimeNum;//加一秒
    }
    else
    {
        timer->stop();
        emit sendTimerState(false);
    }
}

void Clock::getTimerStart()
{
    if(timerStart==false)
    {
        timerStart=true;
        timer->start(speed);
//        qDebug()<<speed;
        connect(timer,SIGNAL(timeout()),this,SLOT(changeCurrentTime()));
    }
    else
    {
//        qDebug()<<speed;
        timer->start(speed);//开启定时器
    }
}

void Clock::getTimerEnd()
{
    timer->stop();//关闭定时器
}

void Clock::getSpeedUp()
{
    speed=speed/2;
    timer->start(speed);
    qDebug()<<"*2";
}

void Clock::getSpeedDown()
{
    speed=speed*2;
    timer->start(speed);
    qDebug()<<"/2";
}

void Clock::getTimerRemake()
{
    currentTimeNum=startTime.fromString(_startTime,"yyyy-MM-dd hh:mm:ss").toTime_t();
    _startTime=startTime.fromTime_t(currentTimeNum).toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<"_startTime"<<_startTime;
    speed=1000;
    update();
}

void Clock::paintEvent(QPaintEvent *ev)
{
    // 时针和分针的点坐标
        //画的是三角形，所以需要三个点的坐标
        static const QPoint hourHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -30)
        };
        static const QPoint minuteHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -60)
        };

        static const QPoint secondHand[3] = {
            QPoint(4, 8),
            QPoint(-4, 8),
            QPoint(0, -100)
        };

        /* 设置时针和分针的颜色 */
        QColor hourColor(127, 0, 127);
        QColor minuteColor(0, 127, 127, 191);
        QColor secondColor(0, 100, 100);

        /* QT自带函数，返回两个数的最小值 */
        int side = qMin(width(), height());
//        qDebug()<<side;

        /* 获取当前时间 */
//        QTime time = QTime::currentTime();
        time=QDateTime::fromString(_currentTime,"yyyy-MM-dd hh:mm:ss");
//        qDebug()<<time;

        /*
            在this这个可绘画设备上创建一个绘画者
            设置渲染，用反锯齿效果
            用一个重载函数转换一下坐标系
            缩放一下这个坐标系
        */
        //The QPainter class performs low-level painting on widgets and other paint devices.
        QPainter painter(this);

        //消除锯齿
        painter.setRenderHint(QPainter::Antialiasing);

        //平移
        painter.translate(width()/2, height()/2);

        //旋转
        painter.scale(side/200.0, side/200.0);

        /* 用一个重载函数设置一下画笔的类型，NoPen就是没有线
           再用一个重载函数设置一下笔刷的颜色，用默认类型
        */
        //Sets the painter's pen to be the given pen.
        //The pen defines how to draw lines and outlines, and it also defines the text color.
        painter.setPen(Qt::NoPen);

        //sets the painter's brush to the given brush.
        //The painter's brush defines how shapes are filled.
        painter.setBrush(hourColor);

        //Saves the current painter state (pushes the state onto a stack).
        //A save() must be followed by a corresponding restore(); the end() function unwinds the stack.
        painter.save(); //保存当前的绘画者状态

        //用给出的角度旋转坐标系
        //Rotates the coordinate system the given angle clockwise.
        painter.rotate(30.0*((time.time().hour()+time.time().minute()/60.0)));

        //用线把点连起来
        //Draws the convex polygon defined by the first pointCount points in the array points using the current pen.
        //The first point is implicitly connected to the last point, and the polygon is filled with the current brush().
        painter.drawConvexPolygon(hourHand, 3);

        //恢复当前的绘画者状态
        //Restores the current painter state (pops a saved state off the stack).
        painter.restore();

        painter.setPen(hourColor);

        /* 画代表小时的线 */
        for (int i = 0; i < 12; ++i) {
            //Draws a line from (x1, y1) to (x2, y2) and sets the current pen position to (x2, y2).
            painter.drawLine(88, 0, 96, 0);
            painter.rotate(30.0);
        }

        //下面画分钟的过程是上面的重复，只是分针的颜色用到了透明度
        painter.setPen(Qt::NoPen);
        painter.setBrush(minuteColor);
        painter.save();
        painter.rotate(6.0*(time.time().minute()+time.time().second()/60.0));
        painter.drawConvexPolygon(minuteHand, 3);
        painter.restore();
        painter.setPen(minuteColor);

        /* 画代表分钟的线 */
        for (int j = 0; j < 60; ++j) {
            if((j % 5) != 0) {
                painter.drawLine(92, 0, 96,0);
            }
            painter.rotate(6.0);
        }

        //下面画秒针的过程是上面的重复
        painter.setPen(Qt::NoPen);
        painter.setBrush(secondColor);
        painter.save();
        painter.rotate(6.0*(time.time().second()));
        painter.drawConvexPolygon(secondHand, 3);
        painter.restore();
        painter.setPen(minuteColor);
}
