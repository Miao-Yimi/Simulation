#ifndef EDITWIDGET_H
#define EDITWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QMouseEvent>
#include <QKeyEvent>

class EditWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EditWidget(QWidget *parent = nullptr);

    QLineEdit *edit;

protected:
    void  mousePressEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent *ev);

signals:
    void sendClicked();
    void sendKeyPressed();

};

#endif // EDITWIDGET_H
