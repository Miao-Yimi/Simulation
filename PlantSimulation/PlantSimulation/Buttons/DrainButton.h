#ifndef DRAINBUTTON_H
#define DRAINBUTTON_H


#include "Widgets/DrainWidget.h"
#include <QWidget>

class DrainButton : public QPushButton
{
    Q_OBJECT
public:
    explicit DrainButton(QWidget *parent = nullptr);

//    QPushButton *drainButton;



signals:
    void sendCreateDrain();

private slots:
    void drainButtonClicked();

};

#endif // DRAINBUTTON_H
