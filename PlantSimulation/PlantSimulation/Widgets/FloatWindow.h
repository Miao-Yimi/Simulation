#ifndef FLOATWINDOW_H
#define FLOATWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPainter>

class FloatWindow : public QDialog
{
    Q_OBJECT
public:
    explicit FloatWindow(QWidget *parent = nullptr);

//    void paintEvent(QPaintEvent *event);
    void getWorkState(QString);
    QLabel *label,*label2;
    QString state;

private:

signals:

private slots:


};

#endif // FLOATWINDOW_H
