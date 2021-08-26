#ifndef DRAINWINDOW_H
#define DRAINWINDOW_H


#include "TextOptions/LabelEditCheck.h"
#include "Tab/DrainTab.h"
#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class DrainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DrainWindow(QWidget *parent = nullptr);

    LabelEditCheck *textOption,*textOption2;
    DrainTab *drainTab;
    QPushButton *determine,*application,*cancel;

    int timeInterval;
    int startTime,endTime;
    QVector<int> workTime;

protected:

private:
    QString nameLabel;

signals:
    void sendWorkTime(QString,QVector<int>);

private slots:
    void getTimeInterval(int);//获取Source工作时间间隔
    void getStartTime(int);//获取Source开始仿真时间
    void getEndTime(int);//获取Source结束仿真时间
    void getWorkTime();

};


#endif // DRAINWINDOW_H
