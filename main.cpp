
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("OPC Test");

    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();

}

