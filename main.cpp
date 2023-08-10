#include "mainwindow.h"

#include <QApplication>
#include "visualizerwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    VisualizerWidget* vis = new VisualizerWidget(&w);
    vis->show();
    vis->setFixedSize(300,300);
    w.setFixedSize(300,300);
    w.show();
    return a.exec();
}
