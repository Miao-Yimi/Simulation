#include "StationFrom.h"
#include "TextOptions/LabelComEditCheck.h"
#include "TextOptions/LabelCom.h"

StationFrom::StationFrom(QWidget *parent) : QWidget(parent)
{
    processing = new LabelComEditCheck(this);
    processing->setGeometry(0,20,1000,100);
    processing->label->setText("Processing time:");
    processing->edit->edit->setInputMask("00:00:00");
    processing->edit->edit->setText("00:00:10");
//    processing->edit->setGeometry(0,0,320,30);
    processing->combo->addItem("Const1");
    processing->combo->addItem("Const2");
    processing->combo->addItem("Const3");


    set_up = new LabelComEditCheck(this);
    set_up->label->setText("Set-Up time:");
    set_up->edit->edit->setInputMask("0000-00-00 00:00:00");
    set_up->edit->edit->setText("2020-10-21 09:14:30");
//    set_up->edit->setGeometry(0,0,320,30);
    set_up->setGeometry(0,65,1000,100);

    recovery = new LabelComEditCheck(this);
    recovery->label->setText("Recovery time:");
    recovery->edit->edit->setInputMask("0000-00-00 00:00:00");
    recovery->edit->edit->setText("2020-10-21 09:15:30");
//    recovery->edit->setGeometry(0,0,320,30);
    recovery->setGeometry(0,110,1000,100);

    recovery_start = new LabelCom(this);
    recovery_start->label->setText("Recovery start time:");
    recovery_start->setGeometry(0,155,1000,100);

    cycle = new LabelComEditCheck(this);
    cycle->label->setText("Cycle time:");
    cycle->edit->edit->setInputMask("0000-00-00 00:00:00");
//    cycle->edit->setGeometry(0,0,320,30);
    cycle->setGeometry(0,200,1000,100);


}
