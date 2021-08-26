#include "StationTab.h"
#include "From/StationFrom.h"
#include <QTabWidget>
#include <QHBoxLayout>

StationTab::StationTab(QWidget *parent) : QWidget(parent)
{
    QTabWidget *tabwidegt=new QTabWidget(this);

    stationFrom1=new StationFrom(this);

    stationFrom2=new StationFrom(this);

    tabwidegt->addTab(stationFrom1,tr("Times"));
    tabwidegt->addTab(stationFrom2,tr("Set-Up"));


    QHBoxLayout *lay=new QHBoxLayout();
    lay->addWidget(tabwidegt);
    lay->setGeometry(QRect(30,200,100,100));

    this->setLayout(lay);
}
