#include "rectangle.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>
#include <QDebug>
#include <mainwindow.h>

Rectangle::Rectangle(int X, int Y, Shape *parent)
    : Shape(parent)
{
    startX=X;
    startY=Y;
    coordinatesCount = 8;
    coordinates = new int[coordinatesCount];
    coordinates[0]=startX;
    coordinates[1]=startY;
    coordinates[2]=startX+200;
    coordinates[3]=startY;
    coordinates[4]=startX+200;
    coordinates[5]=+startY+100;
    coordinates[6]=startX;
    coordinates[7]=startY+100;
    Centre(centreX, centreY);
}

void Rectangle::doPainting(){
    QPainter painter(this);

    painter.setPen(QPen(QBrush("#888"), 1));
    painter.setBrush(QBrush(QColor("#888")));

    QPolygon polygon({QPoint(coordinates[0], coordinates[1]),QPoint(coordinates[2], coordinates[3]),
                      QPoint(coordinates[4], coordinates[5]),QPoint(coordinates[6], coordinates[7])});

    painter.drawPolygon(polygon);

    if (coordinates[0] >= 520){
        killTimer(timerId);
        timerId = -1;
        coordinates[0]=startX;
        coordinates[1]=startY;
        coordinates[2]=startX+200;
        coordinates[3]=startY;
        coordinates[4]=startX+200;
        coordinates[5]=+startY+100;
        coordinates[6]=startX;
        coordinates[7]=startY+100;
    }

    if(scaleDelta <= 0){
        killTimer(scaleTimerId);
        scaleTimerId = -1;
    }

    if(rotateAngle >= 360){
        killTimer(rotateTimerId);
        rotateTimerId = -1;
    }
}

double Rectangle::Square(){
    int a = coordinates[2]-coordinates[0];
    int b = coordinates[5]-coordinates[3];
    double S=a*b;
    return S;
}

double Rectangle::Perimeter(){
    int a = coordinates[2]-coordinates[0];
    int b = coordinates[5]-coordinates[3];
    double P=2*a+2*b;
    return P;
}

void Rectangle::Centre(double &x, double &y){
    int a = coordinates[2]-coordinates[0];
    int b = coordinates[5]-coordinates[3];
    x=coordinates[0]+0.5*a;
    y=coordinates[1]+0.5*b;
}

