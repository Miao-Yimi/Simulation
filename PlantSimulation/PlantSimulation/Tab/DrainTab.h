#ifndef DRAINTAB_H
#define DRAINTAB_H


#include "From/DrainFrom.h"
#include <QObject>
#include <QWidget>

class DrainTab : public QWidget
{
    Q_OBJECT
public:
    explicit DrainTab(QWidget *parent = nullptr);

    DrainFrom *drainFrom1,*drainFrom2;

protected:

private:


signals:

};


#endif // DRAINTAB_H
