#ifndef UPBUTTON_H
#define UPBUTTON_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>

class UpButton : public QWidget
{
    Q_OBJECT
public:
    explicit UpButton(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);

signals:
    void sendClicked();

};

#endif // UPBUTTON_H
