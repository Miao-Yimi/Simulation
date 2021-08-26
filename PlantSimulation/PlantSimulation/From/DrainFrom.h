#ifndef DRAINFROM_H
#define DRAINFROM_H

#include "TextOptions/LabelComEditCheck.h"
#include "TextOptions/LabelCom.h"
#include <QWidget>

class DrainFrom : public QWidget
{
    Q_OBJECT
public:
    explicit DrainFrom(QWidget *parent = nullptr);

    LabelComEditCheck *processing;
    LabelComEditCheck *set_up;
    LabelComEditCheck *recovery;
    LabelCom *recovery_start;
    LabelComEditCheck *cycle;

protected:

private:


signals:

};


#endif // DRAINFROM_H
