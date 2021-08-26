#ifndef SOURCEFROM_H
#define SOURCEFROM_H


#include "TextOptions/LabelComEditCheck.h"
#include "TextOptions/LabelCom.h"
#include <QWidget>

class SourceFrom : public QWidget
{
    Q_OBJECT
public:
    explicit SourceFrom(QWidget *parent = nullptr);

    LabelComEditCheck *processing;
    LabelComEditCheck *set_up;
    LabelComEditCheck *recovery;
    LabelCom *recovery_start;
    LabelComEditCheck *cycle;

protected:

private:


signals:

private slots:


};

#endif // SOURCEFROM_H
