#include "mainwindow.h"
#include "rectangle.h"
#include "train.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(830, 530);
    w.setWindowTitle("Train");
    w.show();
    return a.exec();
}
