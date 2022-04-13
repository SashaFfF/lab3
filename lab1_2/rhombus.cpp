#include "rhombus.h"
#include "shape.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Rhombus::Rhombus(int X, int Y, Shape *parent)
    : Shape(parent)
{
    startX=X;
    startY=Y;
    coordinatesCount = 8;
    coordinates = new int[coordinatesCount];
    coordinates[0]=startX;
    coordinates[1]=startY+50;
    coordinates[2]=startX+50;
    coordinates[3]=startY;
    coordinates[4]=startX+100;
    coordinates[5]=startY+50;
    coordinates[6]=startX+50;
    coordinates[7]=startY+100;
    Centre(centreX, centreY);
}

void Rhombus::doPainting() {

  QPainter painter(this);

  painter.setPen(QPen(QBrush("#888"), 1));
  painter.setBrush(QBrush(QColor("#888")));

  QPolygon polygon({QPoint(coordinates[0], coordinates[1]),QPoint(coordinates[2], coordinates[3]),
                    QPoint(coordinates[4], coordinates[5]),QPoint(coordinates[6], coordinates[7])});

  painter.drawPolygon(polygon);

  if (coordinates[0] >= 520){
      killTimer(timerId);
      coordinates[0]=startX;
      coordinates[1]=startY+50;
      coordinates[2]=startX+50;
      coordinates[3]=startY;
      coordinates[4]=startX+100;
      coordinates[5]=startY+50;
      coordinates[6]=startX+50;
      coordinates[7]=startY+100;
  }

  if(scaleDelta <= 0){
      killTimer(scaleTimerId);
      scaleTimerId = -1;
  }


  if(rotateAngle >= 315){
      killTimer(rotateTimerId);
      rotateTimerId = -1;
      rotateAngle = 0;
  }
}

double Rhombus::Square(){
    int d1=coordinates[7]-coordinates[3];
    int d2=coordinates[4]-coordinates[0];
    double S=0.5*d1*d2;
    return S;
}

double Rhombus::Perimeter(){
    int d1=coordinates[7]-coordinates[3];
    int d2=coordinates[4]-coordinates[0];
    double P=0.5*sqrt(pow(d1,2)+pow(d2,2));
    return P;
}

void Rhombus::Centre(double &x, double &y){
    x=coordinates[0]+0.5*(coordinates[4]-coordinates[0]);
    y=coordinates[3]+0.5*(coordinates[7]-coordinates[3]);
}
