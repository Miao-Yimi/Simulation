#ifndef STATIONBUTTON_H
#define STATIONBUTTON_H

#include "Widgets/StationWidget.h"
#include <QWidget>

class StationButton : public QPushButton
{
    Q_OBJECT
public:
    explicit StationButton(QWidget *parent = nullptr);

//    QPushButton *stationButton;



signals:
    void sendCreateStation();

private slots:
    void stationButtonClicked();

};

#endif // STATIONBUTTON_H
