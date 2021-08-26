#include "DrainTab.h"
#include "From/SourceFrom.h"
#include <QTabWidget>
#include <QHBoxLayout>

DrainTab::DrainTab(QWidget *parent) : QWidget(parent)
{
    QTabWidget *tabwidegt=new QTabWidget(this);

    drainFrom1=new DrainFrom(this);

    drainFrom2=new DrainFrom(this);

    tabwidegt->addTab(drainFrom1,tr("Times"));
    tabwidegt->addTab(drainFrom2,tr("Set-Up"));


    QHBoxLayout *lay=new QHBoxLayout();
    lay->addWidget(tabwidegt);
    lay->setGeometry(QRect(30,200,100,100));

    this->setLayout(lay);
}


