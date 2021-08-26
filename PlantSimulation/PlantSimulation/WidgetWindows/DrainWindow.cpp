#include "DrainWindow.h"
#include "TextOptions/LabelEditCheck.h"
#include "Widgets/DrainWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDebug>
#include <QPushButton>

DrainWindow::DrainWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    this->resize(800,580);

    this->setWindowTitle("Model Drain");
//    name输入
    textOption=new LabelEditCheck(this);
    textOption2=new LabelEditCheck(this);

    textOption->setGeometry(30,30,300,50);
    textOption2->setGeometry(30,80,300,50);

    textOption->label->setText("Name:");
    textOption->setStyleSheet("QLabel {font:21px;}");

    nameLabel="Drain"+QString::number(DrainWidget::drainNum);
    textOption->edit->edit->setText(nameLabel);
    DrainWidget::drainNum++;

    textOption2->label->setText("Label:");

    drainTab=new DrainTab(this);
    drainTab->setGeometry(15,180,770,330);

    application=new QPushButton("应用",this);
    application->setGeometry(430,530,100,30);

    determine=new QPushButton("确定",this);
    determine->setGeometry(550,530,100,30);

    cancel=new QPushButton("取消",this);
    cancel->setGeometry(670,530,100,30);

    connect(this->drainTab->drainFrom1->processing,SIGNAL(sendTimeInterval(int)),this,SLOT(getTimeInterval(int)));
    connect(this->drainTab->drainFrom1->set_up,SIGNAL(sendDateTimeInterval(int)),this,SLOT(getStartTime(int)));
    connect(this->drainTab->drainFrom1->recovery,SIGNAL(sendDateTimeInterval(int)),this,SLOT(getEndTime(int)));
    connect(this->application,SIGNAL(clicked()),this,SLOT(getWorkTime()));
}

void DrainWindow::getTimeInterval(int _timeInterval)
{
    timeInterval=_timeInterval;
//    qDebug()<<"timeInterval:"<<timeInterval;
}

void DrainWindow::getStartTime(int _startTime)
{
    startTime=_startTime;
//    qDebug()<<"startTime:"<<startTime;
}

void DrainWindow::getEndTime(int _endTime)
{
    endTime=_endTime;
//    qDebug()<<"endTime:"<<endTime;
}

//根据时间间隔与仿真开始、结束时间得到Source可能的工作时间，此时不计算可能的等待时间
void DrainWindow::getWorkTime()
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


