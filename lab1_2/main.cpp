
#include "mainwindow.h"
#include "shape.h"
#include "triangle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1000, 900);
    w.setWindowTitle("Shape");
    w.show();
    return a.exec();
}
