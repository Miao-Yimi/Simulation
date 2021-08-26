#ifndef SOURCEWINDOW_H
#define SOURCEWINDOW_H

#include "TextOptions/LabelEditCheck.h"
#include "Tab/SourceTab.h"
#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class SourceWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SourceWindow(QWidget *parent = nullptr);

    LabelEditCheck *textOption,*textOption2;
    SourceTab *sourceTab;
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



#endif // SOURCEWINDOW_H
