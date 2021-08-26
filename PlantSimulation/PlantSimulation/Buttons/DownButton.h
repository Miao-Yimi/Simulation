#ifndef DOWNBUTTON_H
#define DOWNBUTTON_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>

class DownButton : public QWidget
{
    Q_OBJECT
public:
    explicit DownButton(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);

signals:
    void sendClicked();

};

#endif // DOWNBUTTON_H
