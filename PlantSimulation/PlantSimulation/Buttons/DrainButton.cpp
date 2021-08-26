#include "DrainButton.h"
#include "Widgets/DrainWidget.h"
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>

DrainButton::DrainButton(QWidget *parent) : QPushButton(parent)
{

    this->resize(42,42);
    //设置背景图片
    this->setStyleSheet("border-image:url(:/buttonImages/Pictures/drainbutton.jpg)");
    connect(this,SIGNAL(clicked()),this,SLOT(drainButtonClicked()));
}

void DrainButton::drainButtonClicked()
{
    emit sendCreateDrain();
}


