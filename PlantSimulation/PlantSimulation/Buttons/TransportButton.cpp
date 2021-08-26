#include "TransportButton.h"

TransportButton::TransportButton(QWidget *parent) : QPushButton(parent)
{
    this->resize(42,42);
    //设置背景图片
    this->setStyleSheet("border-image:url(:/buttonImages/Pictures/transportbutton.jpg)");
    connect(this,SIGNAL(clicked()),this,SLOT(transportButtonClicked()));
}

void TransportButton::transportButtonClicked()
{
    emit sendCreateTrans();
}
