#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPushButton>
#include "rectangle.h"
#include "line.h"

#include <QMainWindow>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow();

    private slots:
        void Animation();

    private:
        Rectangle *train;
        Line *line;
        Line *line2;
        QPushButton *start;
        bool flag = true;
};

#endif // MAINWINDOW_H
