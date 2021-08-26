#include "StationWindow.h"
#include "TextOptions/LabelEditCheck.h"
#include "Widgets/StationWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDebug>
#include <QPushButton>

StationWindow::StationWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    this->resize(800,580);

    this->setWindowTitle("Model Station");
//    name输入
    textOption=new LabelEditCheck(this);
    textOption2=new LabelEditCheck(this);

    textOption->setGeometry(30,30,300,50);
    textOption2->setGeometry(30,80,300,50);

    textOption->label->setText("Name:");
    textOption->setStyleSheet("QLabel {font:21px;}");

    nameLabel="Station"+QString::number(StationWidget::stationNum);
    textOption->edit->edit->setText(nameLabel);
    StationWidget::stationNum++;
//    textOption->edit->edit->setText("Station");

    textOption2->label->setText("Label:");

    stationTab=new StationTab(this);
    stationTab->setGeometry(15,180,770,330);

    application=new QPushButton("应用",this);
    application->setGeometry(430,530,100,30);

    determine=new QPushButton("确定",this);
    determine->setGeometry(550,530,100,30);

    cancel=new QPushButton("取消",this);
    cancel->setGeometry(670,530,100,30);

    connect(this->stationTab->stationFrom1->processing,SIGNAL(sendTimeInterval(int)),this,SLOT(getTimeInterval(int)));
    connect(this->stationTab->stationFrom1->set_up,SIGNAL(sendDateTimeInterval(int)),this,SLOT(getStartTime(int)));
    connect(this->stationTab->stationFrom1->recovery,SIGNAL(sendDateTimeInterval(int)),this,SLOT(getEndTime(int)));
    connect(this->application,SIGNAL(clicked()),this,SLOT(getWorkTime()));
}

void StationWindow::getTimeInterval(int _timeInterval)
{
    timeInterval=_timeInterval;
//    qDebug()<<"timeInterval:"<<timeInterval;
}

void StationWindow::getStartTime(int _startTime)
{
    startTime=_startTime;
//    qDebug()<<"startTime:"<<startTime;
}

void StationWindow::getEndTime(int _endTime)
{
    endTime=_endTime;
//    qDebug()<<"endTime:"<<endTime;
}

//根据时间间隔与仿真开始、结束时间得到Station可能的工作时间，此时不计算可能的等待时间
void StationWindow::getWorkTime()
{
    workTime.clear();
    int tempStartTime=startTime;
    while(tempStartTime<=endTime)
    {
        workTime.push_back(tempStartTime);
        tempStartTime+=timeInterval;
    }
//    qDebug()<<tempStartTime;
    if(tempStartTime-timeInterval<endTime)
    {
        workTime.push_back(endTime);
    }
//    qDebug()<<nameLabel<<workTime;
    emit sendWorkTime(nameLabel,workTime);
}
