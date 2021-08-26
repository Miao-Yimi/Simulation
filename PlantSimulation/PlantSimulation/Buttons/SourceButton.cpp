#include "SourceButton.h"
#include "Widgets/SourceWidget.h"
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>

SourceButton::SourceButton(QWidget *parent) : QPushButton(parent)
{
    this->resize(42,42);
    //设置背景图片
    this->setStyleSheet("border-image:url(:/buttonImages/Pictures/sourcebutton.jpg)");
    connect(this,SIGNAL(clicked()),this,SLOT(sourceButtonClicked()));
}

void SourceButton::sourceButtonClicked()
{
    emit sendCreateSource();
}
