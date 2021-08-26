#ifndef SOURCETAB_H
#define SOURCETAB_H

#include "From/SourceFrom.h"
#include <QObject>
#include <QWidget>

class SourceTab : public QWidget
{
    Q_OBJECT
public:
    explicit SourceTab(QWidget *parent = nullptr);

    SourceFrom *sourceFrom1,*sourceFrom2;
protected:

private:


signals:

};


#endif // SOURCETAB_H
