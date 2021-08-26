#ifndef STATIONTAB_H
#define STATIONTAB_H

#include "From/StationFrom.h"
#include <QObject>
#include <QWidget>

class StationTab : public QWidget
{
    Q_OBJECT
public:
    explicit StationTab(QWidget *parent = nullptr);

    StationFrom *stationFrom1,*stationFrom2;

protected:

private:

signals:

};

#endif // STATIONTAB_H
