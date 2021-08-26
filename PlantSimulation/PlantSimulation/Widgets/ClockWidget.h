#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include "WidgetWindows/ClockWindow.h"
#include <QWidget>
#include <QMouseEvent>

class ClockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClockWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *ev);

    ClockWindow *clockWindow;

signals:

private slots:
    void getRaise();

};

#endif // CLOCKWIDGET_H
