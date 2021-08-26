#include "LabelComEditCheck.h"
#include "Widgets/EditWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QKeyEvent>
#include <QDateTime>
#include <QDebug>

LabelComEditCheck::LabelComEditCheck(QWidget *parent) : QWidget(parent)
{
    label=new QLabel(this);
    label->setGeometry(20,20,150,50);

    combo=new QComboBox(this);
    combo->setGeometry(210,30,120,30);

    edit=new EditWidget(this);
    edit->edit->resize(320,30);
    edit->setGeometry(350,30,320,30);

    check=new QCheckBox(this);
    check->setGeometry(690,30,30,30);

    connect(edit,SIGNAL(sendKeyPressed()),this,SLOT(getKeyPressed()));
}

void LabelComEditCheck::getKeyPressed()
{
    str=edit->edit->text();
    if(str.size()==8)
    {
        timeTransform(str);
    }
    else if(str.size()==19)
    {
        dateTimeTransform(str);
    }

}

void LabelComEditCheck::timeTransform(QString _str)
{
    QString temp;
    QVector<QString> time;

    if(_str.size()>0)
    {
//        qDebug()<<"text:"<<_str;
        for(int i=0;i<_str.size();i++)
        {
            if(_str.at(i)==':')
            {
                time.append(temp);
                temp.clear();
            }
            else
            {
                temp+=_str.at(i);

            }
        }
        if(temp.size()!=0)
            time.append(temp);
        hour=time.at(0).toInt();
        min=time.at(1).toInt();
        sec=time.at(2).toInt();

        timeInterval=hour*3600+min*60+sec;
//        qDebug()<<timeInterval;
        emit sendTimeInterval(timeInterval);

        check->setCheckState(Qt::Checked);

    }
}

void LabelComEditCheck::dateTimeTransform(QString _str)
{
    QDateTime time;
    int sec;
    //将指定时间格式字符串转化成秒
    sec=time.fromString(_str,"yyyy-MM-dd hh:mm:ss").toTime_t();
//    qDebug()<<sec;
    emit sendDateTimeInterval(sec);

    check->setCheckState(Qt::Checked);
}
