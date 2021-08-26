#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include "Widgets/Clock.h"
#include "TextOptions/LabelEditCheck.h"
#include "Buttons/StartButton.h"
#include "Buttons/DownButton.h"
#include "Buttons/RemakeButton.h"
#include "Buttons/UpButton.h"
#include <QWidget>

class ClockWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ClockWindow(QWidget *parent = nullptr);

    LabelEditCheck *textOption1,*textOption2;
    Clock *clock;

private:
    bool timerState;//定时器状态
    StartButton *startButton;
    UpButton *upButton;
    DownButton *downButton;
    RemakeButton *remakeButton;

signals:
    void sendTimerStart();//发送定时器启动信号，开始仿真
    void sendTimerEnd();//发送定时器关闭信号，结束仿真
    void sendSpeedUp();//发送加速信号
    void sendSpeedDown();//发送减速信号
    void sendTimerRemake();//发送复位信号
    void sendState();//发送状态改变信号

private slots:
    void StartButtonClicked();
    void UpButtonClicked();
    void DownButtonClicked();
    void RemakeButtonClicked();
    void getTimerState(bool);

};

#endif // CLOCKWINDOW_H
