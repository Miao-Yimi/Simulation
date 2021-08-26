#include "CableButton.h"

CableButton::CableButton(QWidget *parent) : QPushButton(parent)
{
    this->resize(42,42);
    //设置背景图片
    this->setStyleSheet("border-image:url(:/buttonImages/Pictures/linebutton.jpg)");
    connect(this,SIGNAL(clicked()),this,SLOT(lineButtonClicked()));
}

void CableButton::lineButtonClicked()
{
    emit sendCreateCable();
}
