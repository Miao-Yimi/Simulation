#include "LabelCom.h"
#include <QLabel>
#include <QComboBox>

LabelCom::LabelCom(QWidget *parent) : QWidget(parent)
{
    label = new QLabel(this);
    label->setGeometry(20,20,180,50);

    combo = new QComboBox(this);
    combo->setGeometry(210,30,320,30);

}
