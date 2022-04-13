#include <QPainter>
#include <QTimer>
#include <QGridLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "train.h"
#include "line.h"

MainWindow::MainWindow()
{
    train = new Train;
    line = new Line(50.0);
    line2 =  new Line(125.0);
    start = new QPushButton("START");
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(train, 0,0,1,4);
    mainLayout->addWidget(line, 0,0,1,4);
    mainLayout->addWidget(line2,0,0,1,4);
    mainLayout->addWidget(start,2,1);
    connect(start, &QPushButton::clicked,this, &MainWindow::Animation);
    setLayout(mainLayout);
}

void MainWindow::Animation()
{
    flag =! flag;
    if(flag){
        start->setText("START");
        train->stop();
        line->stop();
        line2->stop();
    }
    else {
        start->setText("STOP");
        train->start();
        line->start();
        line2->start();

    }
}


