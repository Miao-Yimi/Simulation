#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QDateTime>
#include <QMap>
#include <QVector>

class Clock : public QWidget
{
    Q_OBJECT
public:
    explicit Clock(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *ev);

    void arrangeTime(QString,QVector<int>);

protected:


private:
    QTimer *timer;
    QDateTime time,startTime,endTime;
    QString _startTime,_endTime,_currentTime;
    int startTimeNum,endTimeNum,currentTimeNum;
    int speed;
    bool timerStart,timeState;
    QVector<int> workTime;
    QMap< int,QVector<QString> > timerReceiver;
    QMap< QString,int> widgetStartTime;
    QMap< QString,int> widgetEndTime;


signals:
    void sendTimerState(bool);
    void sendStartSimulation(QString);
    void sendEndSimulation(QString);
    void sendWorkStart(int,QString);

private slots:
    void getTimerStart();
    void getTimerEnd();
    void getSpeedUp();
    void getSpeedDown();
    void getTimerRemake();
    void changeCurrentTime();
    void getStartTime(QString);
    void getEndTime(QString);
    void getWorkTime(QString,QVector<int>);
    void getDeleteWidget(QString);
};

#endif // CLOCK_H
