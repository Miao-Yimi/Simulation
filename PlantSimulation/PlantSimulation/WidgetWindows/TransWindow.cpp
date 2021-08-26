#include "TransWindow.h"
#include "TextOptions/LabelEditCheck.h"
#include "Widgets/TransWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDebug>
#include <QPushButton>

TransWindow::TransWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    this->resize(800,580);

    this->setWindowTitle("Model Transporter");
//    name输入
    textOption=new LabelEditCheck(this);
    textOption2=new LabelEditCheck(this);

    textOption->setGeometry(30,30,300,50);
    textOption2->setGeometry(30,80,300,50);

    textOption->label->setText("Name:");
    textOption->setStyleSheet("QLabel {font:21px;}");

    nameLabel="Transport"+QString::number(TransWidget::transNum);
    textOption->edit->edit->setText(nameLabel);
    TransWidget::transNum++;

    textOption2->label->setText("Length:");
    textOption2->edit->edit->setText("150");
}
