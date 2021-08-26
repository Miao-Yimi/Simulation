#include "EditWidget.h"
#include <QLineEdit>
#include <QDebug>

EditWidget::EditWidget(QWidget *parent) : QWidget(parent)
{
    edit=new QLineEdit(this);
    edit->setGeometry(0,0,140,30);
}

//此函数无法触发
void EditWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
//        qDebug()<<"edit clicked";
        emit sendClicked();
    }
}

void EditWidget::keyPressEvent(QKeyEvent *ev)
{
     if(ev->key()==Qt::Key_Enter||ev->key()==Qt::Key_Return)
     {
//         qDebug()<<"edit pressed";
         emit sendKeyPressed();
     }
}
