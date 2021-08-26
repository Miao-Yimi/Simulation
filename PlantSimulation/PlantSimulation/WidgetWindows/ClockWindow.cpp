#include "ClockWindow.h"
#include "Widgets/Clock.h"
#include "TextOptions/LabelEditCheck.h"
#include "Buttons/StartButton.h"
#include "Buttons/DownButton.h"
#include "Buttons/RemakeButton.h"
#include "Buttons/UpButton.h"
#include <QPainter>
#include <QPixmap>

ClockWindow::ClockWindow(QWidget *parent) : QWidget(parent)
{
    //窗口置顶
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    this->setWindowTitle("Clock");
    this->resize(630,230);
    timerState=false;//定时器处于未开启状态

    clock = new Clock(this);
    clock->setGeometry(15,15,200,200);


    textOption1=new LabelEditCheck(this);
    textOption1->label->setText("Start time:");
    textOption1->label->resize(100,30);
    textOption1->edit->edit->setText("2020-10-21 09:14:00");
    textOption1->edit->edit->setInputMask("0000-00-00 00:00:00");
    textOption1->edit->edit->resize(210,30);
    textOption1->edit->setGeometry(120,0,210,30);
    textOption1->check->setGeometry(350,0,30,30);
    textOption1->setGeometry(240,50,420,30);

    textOption2=new LabelEditCheck(this);
    textOption2->label->setText("End time:");
    textOption2->label->resize(100,30);
    textOption2->edit->edit->setText("2020-10-21 09:15:30");
    textOption2->edit->edit->setInputMask("0000-00-00 00:00:00");
    textOption2->edit->edit->resize(210,30);
    textOption2->edit->setGeometry(120,0,210,30);
    textOption2->check->setGeometry(350,0,30,30);
    textOption2->setGeometry(240,100,420,30);

    startButton=new StartButton(this);
    startButton->setGeometry(506,150,50,50);

    upButton=new UpButton(this);
    upButton->setGeometry(576,150,50,50);

    downButton=new DownButton(this);
    downButton->setGeometry(433,150,50,50);

    remakeButton=new RemakeButton(this);
    remakeButton->setGeometry(360,150,50,50);

    //定时器开启、关闭
    connect(startButton,SIGNAL(sendClicked()),this,SLOT(StartButtonClicked()));
    connect(this,SIGNAL(sendTimerStart()),clock,SLOT(getTimerStart()));
    connect(this,SIGNAL(sendTimerEnd()),clock,SLOT(getTimerEnd()));

    //加速，speed*2
    connect(upButton,SIGNAL(sendClicked()),this,SLOT(UpButtonClicked()));
    connect(this,SIGNAL(sendSpeedUp()),clock,SLOT(getSpeedUp()));

    //减速,speed/2
    connect(downButton,SIGNAL(sendClicked()),this,SLOT(DownButtonClicked()));
    connect(this,SIGNAL(sendSpeedDown()),clock,SLOT(getSpeedDown()));

    //复位重置
    connect(remakeButton,SIGNAL(sendClicked()),this,SLOT(RemakeButtonClicked()));
    connect(this,SIGNAL(sendTimerRemake()),clock,SLOT(getTimerRemake()));

    //获取仿真开始时间
    connect(textOption1,SIGNAL(sendTime(QString)),clock,SLOT(getStartTime(QString)));
    //获取仿真结束时间
    connect(textOption2,SIGNAL(sendTime(QString)),clock,SLOT(getEndTime(QString)));

    //仿真结束，调整startButton显示的定时器状态
    connect(clock,SIGNAL(sendTimerState(bool)),this,SLOT(getTimerState(bool)));
    connect(clock,SIGNAL(sendTimerState(bool)),startButton,SLOT(getTimerState(bool)));
}

void ClockWindow::getTimerState(bool _timerState)
{
    timerState=_timerState;
}

void ClockWindow::StartButtonClicked()
{
    if(timerState==false){
        timerState=true;//开启定时器，启动仿真
        emit sendTimerStart();//发送开启定时器信号
    }
    else
    {
        timerState=false;//关闭定时器，结束仿真
        emit sendTimerEnd();//发送关闭定时器信号
    }
}

void ClockWindow::UpButtonClicked()
{
    emit sendSpeedUp();
}

void ClockWindow::DownButtonClicked()
{
    emit sendSpeedDown();
}

void ClockWindow::RemakeButtonClicked()
{
    emit sendTimerRemake();
}
