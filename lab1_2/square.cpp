#include "square.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Square2::Square2(int X, int Y, Shape *parent)
    : Shape(parent)
{
    startX = X;
    startY = Y;
    coordinatesCount = 8;
    coordinates = new int[coordinatesCount];
    coordinates[0]=startX;
    coordinates[1]=startY+50;
    coordinates[2]=startX+100;
    coordinates[3]=startY+50;
    coordinates[4]=startX+100;
    coordinates[5]=startY+150;
    coordinates[6]=startX;
    coordinates[7]=startY+150;
    Centre(centreX, centreY);
}

void Square2::doPainting() {
  QPainter painter(this);

  painter.setPen(QColor("#0509b5"));
  painter.setBrush(QBrush("#0509b5"));

  QPolygon polygon({QPoint(coordinates[0], coordinates[1]),QPoint(coordinates[2], coordinates[3]),
                    QPoint(coordinates[4], coordinates[5]),QPoint(coordinates[6], coordinates[7])});

  painter.drawPolygon(polygon);

  if (coordinates[0] >= 520){
      killTimer(timerId);
      coordinates[0]=startX;
      coordinates[1]=startY+50;
      coordinates[2]=startX+100;
      coordinates[3]=startY+50;
      coordinates[4]=startX+100;
      coordinates[5]=startY+150;
      coordinates[6]=startX;
      coordinates[7]=startY+150;
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

double Square2:: Square(){
    int a=coordinates[2]-coordinates[0];
    double S = pow(a, 2);
    return S;
}

double Square2::Perimeter(){
    int a=coordinates[2]-coordinates[0];
    double P=4*a;
    return P;
}

void Square2::Centre(double &x, double &y){
    int a=coordinates[2]-coordinates[0];
    x=coordinates[0]+0.5*a;
    y=coordinates[1]+0.5*a;
}


