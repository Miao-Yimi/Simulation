#include "LabelEditCheck.h"
#include "Widgets/EditWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>

LabelEditCheck::LabelEditCheck(QWidget *parent) : QWidget(parent)
{
    label=new QLabel(this);
    label->setGeometry(0,0,50,50);

    edit=new EditWidget(this);
    edit->setGeometry(70,10,140,30);

    check=new QCheckBox(this);
    check->setGeometry(230,10,30,30);

    connect(edit,SIGNAL(sendKeyPressed()),this,SLOT(getKeyPressed()));

}


void LabelEditCheck::getKeyPressed()
{
    str=edit->edit->text();
    fontWidth=fontMetrics().width(str);
    check->setCheckState(Qt::Checked);
    emit sendName(str,fontWidth);
    emit sendUpdate();

    emit sendTime(str);
    emit sendLength(str);

}

