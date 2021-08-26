#include "TransWidget.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>

int TransWidget::transNum=1;

TransWidget::TransWidget(QWidget *parent) : QWidget(parent)
{
    pressState=false;
    enterState=false;
    pointNum=2;
    transLong=150;
    A2X=450;
    A2Y=245;
    A1X=this->x();
    A1Y=this->y();

    getTransNumber(transNum);

    transWindow=new TransWindow;
    transWindow->hide();//窗口处于隐藏状态
    transWindow->setFixedSize(800,580);

    this->setMouseTracking(true);//开启跟踪鼠标功能

    linkPoint1=QPointF(A2X+transLong/2,A2Y+20);

//    改变传送带名字和长度
    connect(transWindow->textOption,SIGNAL(sendName(QString,int)),this,SLOT(getName(QString,int)));
    connect(transWindow->textOption2,SIGNAL(sendLength(QString)),this,SLOT(getLength(QString)));
    connect(transWindow->textOption,SIGNAL(sendUpdate()),this,SLOT(getUpdate()));
}

void TransWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        pressState=true;
        this->setFocus();
        emit sendFocus(pressState,transCode);//发送widget已经被选中的信号,需要将其他焦点屏蔽

        PressX=ev->globalX();//鼠标相对于桌面显示器的位置
        PressY=ev->globalY();

        A1X=this->x();//widget左上角相对于程序窗口的位置
        A1Y=this->y();

        emit sendWindowHide();

        linkPoint1=QPointF(A1X+transLong/2,A1Y+20);
        emit sendLinkPoint(linkPoint1,transCode,pointNum,transLong);

    }
    update();

}

void TransWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons()==Qt::LeftButton)
    {
        CurrentX=ev->globalX();
        CurrentY=ev->globalY();

        A2X=A1X+CurrentX-PressX;
        A2Y=A1Y+CurrentY-PressY;

        emit sendWindowHide();

        linkPoint1=QPointF(A2X+transLong/2,A2Y+20);
        emit sendMoveLinkPoint(linkPoint1,transCode,pointNum,transLong);
        update();
    }
}

void TransWidget::mouseReleaseEvent(QMouseEvent *ev)
{
//    pressState=false;
    update();
}

void TransWidget::mouseDoubleClickEvent(QMouseEvent *ev)
{
    transWindow->show();
    update();
}

void TransWidget::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_Delete)
    {
//        qDebug()<<this->hasFocus();//判断焦点是否在widget上
//        发送widget取消选中的信号，但此时是因为widget被删除
        if(this->hasFocus()==true){
            emit sendFocus(pressState,transCode);
            pressState=false;
            emit sendDeleteWidget(transCode);//发送该控件被删除的信号
            delete this;
        }
    }
    else if(ev->key()==Qt::Key_Escape)
    {
//        widget通过esc取消聚焦
//        qDebug()<<"enter";
        pressState=false;
        this->setFocusPolicy(Qt::NoFocus);
        update();
        emit sendFocus(pressState,transCode);
    }
}

void TransWidget::getChangeFocus(QString _name)
{
    if(_name==transCode&&pressState==true)
    {
        pressState=false;
//        屏蔽焦点
        this->setFocusPolicy(Qt::NoFocus);
        update();
    }
}

void TransWidget::getName(QString _name,int _fontwidth)
{
    name=_name;
    fontDis=(transLong-_fontwidth)/2;
//    qDebug()<<name;
}

//调整传送带长度
void TransWidget::getLength(QString _length)
{
    double length=_length.toDouble();

    transLong=length;
    fontDis=(transLong-fontMetrics().width(name))/2;  
    linkPoint1=QPointF(A2X+transLong/2,A2Y+20);
    update();
    emit sendChangeCableLength(linkPoint1,transCode,transLong);
    emit sendChangeCableLength(linkPoint1,transCode,transLong);
}

void TransWidget::getUpdate()
{
    update();
}

void TransWidget::getRaise()
{
    this->raise();
}

void TransWidget::getTransNumber(int _transNum)
{
    name="Transport"+QString::number(_transNum);
    transCode="Transport"+QString::number(_transNum);
    fontDis=(transLong-fontMetrics().width(name))/2;
//    qDebug()<<name;
}

void TransWidget::paintEvent(QPaintEvent *ev)
{
    QPixmap pixmap(transLong,68);//控件图标大小为transLong*60
    pixmap.fill(Qt::transparent);

    QPainter p(&pixmap);
    p.setBrush(QColor(176,196,222));
    p.setPen(QColor(176,196,222));
    p.drawRect(0,0,transLong,40);

    p.setPen(Qt::black);
    p.drawText(fontDis,60,name);

    if(pressState==true)
    {
        p.setBrush(QColor(200,200,200,100));
        p.setPen(QColor(200,200,200,100));
        p.drawRect(0,0,transLong,68);
    }

    p.end();
    this->resize(transLong,68);
    p.begin(this);

    p.drawPixmap(0,0,pixmap);
    this->move(A2X,A2Y);
}
