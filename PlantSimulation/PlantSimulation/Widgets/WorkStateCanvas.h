#ifndef WORKSTATECANVAS_H
#define WORKSTATECANVAS_H

#include "Widgets/FloatWindow.h"
#include <QWidget>

class WorkStateCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit WorkStateCanvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *ev);

signals:

private slots:
    void getCreateStationWindow();//同步创建station悬浮窗口
    void getCreateSourceWindow();//同步创建source悬浮窗口
    void getStationShow();//显示station悬浮窗口
    void getStationHide();//隐藏station悬浮窗口

};

#endif // WORKSTATECANVAS_H
