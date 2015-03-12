#include "startmenu.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startmenu w;
    w.show();

    return a.exec();
}
