#include "StationButton.h"
#include "Widgets/StationWidget.h"
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>

StationButton::StationButton(QWidget *parent) : QPushButton(parent)
{

    this->resize(42,42);
    //设置背景图片
    this->setStyleSheet("border-image:url(:/buttonImages/Pictures/stationbutton.jpg)");
    connect(this,SIGNAL(clicked()),this,SLOT(stationButtonClicked()));
}

void StationButton::stationButtonClicked()
{
    emit sendCreateStation();
}



