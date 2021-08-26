#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>

class StartButton : public QWidget
{
    Q_OBJECT
public:
    explicit StartButton(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);
    bool timerState;

signals:
    void sendClicked();

private slots:
    void getTimerState(bool);

};

#endif // STARTBUTTON_H
