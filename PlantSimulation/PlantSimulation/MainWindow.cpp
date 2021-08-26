#include "MainWindow.h"
#include "Widgets/SourceWidget.h"
#include "Widgets/StationWidget.h"
#include "Widgets/DrainWidget.h"
#include "Widgets/ClockWidget.h"
#include "Widgets/Canvas.h"
#include "Widgets/CableCanvas.h"
#include "Buttons/StationButton.h"
#include "Buttons/SourceButton.h"
#include "Buttons/DrainButton.h"
#include "Buttons/CableButton.h"
#include "Buttons/TransportButton.h"
#include <QApplication>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
//    CableCanvas *cableCanvas=new CableCanvas(this);
//    cableCanvas->setGeometry(200,200,1964,1200);

    Canvas *canvas=new Canvas(this);//widgets画布
    canvas->setGeometry(200,200,1964,1200);

    SourceButton *sourceButton=new SourceButton(this);
    sourceButton->setGeometry(200,0,42,42);
    connect(sourceButton,SIGNAL(sendCreateSource()),canvas,SLOT(getCreateSource()));

    StationButton *stationButton=new StationButton(this);
    stationButton->setGeometry(242,0,42,42);
    //创建station对象
    connect(stationButton,SIGNAL(sendCreateStation()),canvas,SLOT(getCreateStation()));

    DrainButton *drainButton=new DrainButton(this);
    drainButton->setGeometry(284,0,42,42);
    connect(drainButton,SIGNAL(sendCreateDrain()),canvas,SLOT(getCreateDrain()));


    CableButton *cableButton=new CableButton(this);
    cableButton->setGeometry(326,0,42,42);
    connect(cableButton,SIGNAL(sendCreateCable()),canvas,SLOT(getTwoPoint()));

    TransportButton *transportButton=new TransportButton(this);
    transportButton->setGeometry(368,0,42,42);
    connect(transportButton,SIGNAL(sendCreateTrans()),canvas,SLOT(getCreateTrans()));

}


int main(int argc,char*argv[])
{
    QApplication app(argc,argv);

    MainWindow w;

    w.showMaximized();
//    w.setStyleSheet("background-color:white");
    w.setWindowTitle("离线仿真软件");

    w.show();

    return app.exec();
}


