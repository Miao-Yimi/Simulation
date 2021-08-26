#include "SourceTab.h"
#include "From/SourceFrom.h"
#include <QTabWidget>
#include <QHBoxLayout>

SourceTab::SourceTab(QWidget *parent) : QWidget(parent)
{
    QTabWidget *tabwidegt=new QTabWidget(this);

    sourceFrom1=new SourceFrom(this);

    sourceFrom2=new SourceFrom(this);

    tabwidegt->addTab(sourceFrom1,tr("Attributes"));
    tabwidegt->addTab(sourceFrom2,tr("Failures"));


    QHBoxLayout *lay=new QHBoxLayout();
    lay->addWidget(tabwidegt);
    lay->setGeometry(QRect(30,200,100,100));

    this->setLayout(lay);
}
