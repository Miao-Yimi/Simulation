#ifndef STATIONFROM_H
#define STATIONFROM_H

#include "TextOptions/LabelComEditCheck.h"
#include "TextOptions/LabelCom.h"
#include <QWidget>

class StationFrom : public QWidget
{
    Q_OBJECT
public:
    explicit StationFrom(QWidget *parent = nullptr);

    LabelComEditCheck *processing;
    LabelComEditCheck *set_up;
    LabelComEditCheck *recovery;
    LabelCom *recovery_start;
    LabelComEditCheck *cycle;

protected:

private:


signals:

};

#endif // STATIONFROM_H
