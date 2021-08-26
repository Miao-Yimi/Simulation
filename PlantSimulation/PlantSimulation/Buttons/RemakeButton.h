#ifndef REMAKEBUTTON_H
#define REMAKEBUTTON_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>

class RemakeButton : public QWidget
{
    Q_OBJECT
public:
    explicit RemakeButton(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);

signals:
    void sendClicked();

};

#endif // REMAKEBUTTON_H
