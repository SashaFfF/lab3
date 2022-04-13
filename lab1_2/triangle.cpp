#include "triangle.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Triangle::Triangle(int X, int Y, Shape *parent)
    : Shape(parent)
{
    startX=X;
    startY=Y;
    coordinatesCount = 6;
    coordinates = new int[coordinatesCount];
    coordinates[0]=startX;
    coordinates[1]=startY;
    coordinates[2]=startX-25;
    coordinates[3]=startY+80;
    coordinates[4]=startX+25;
    coordinates[5]=startY+80;
    Centre(centreX, centreY);
}

void Triangle::doPainting() {

  QPainter painter(this);

  painter.setPen(QPen(QBrush("#888"), 1));
  painter.setBrush(QBrush(QColor("#888")));

  QPolygon polygon({QPoint(coordinates[0], coordinates[1]),QPoint(coordinates[2], coordinates[3]), QPoint(coordinates[4], coordinates[5])});

  painter.drawPolygon(polygon);

  if (coordinates[0] >= 520){
      killTimer(timerId);
      coordinates[0]=150;
      coordinates[1]=150;
      coordinates[2]=125;
      coordinates[3]=230;
      coordinates[4]=175;
      coordinates[5]=230;
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

double Triangle::Square(){
    int x1 = coordinates[0];
    int y1 = coordinates[1];
    int x2 = coordinates[2];
    int y2 = coordinates[3];
    int x3 = coordinates[4];
    int y3 = coordinates[5];
    double S=0.5*abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
    return S;
}

double Triangle::Perimeter(){
    int x1 = coordinates[0];
    int y1 = coordinates[1];
    int x2 = coordinates[2];
    int y2 = coordinates[3];
    int x3 = coordinates[4];
    int y3 = coordinates[5];
    double a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    double b=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    double c=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    double P=a+b+c;
    return P;
}


void Triangle::Centre(double& x, double& y){
    int x1 = coordinates[0];
    int y1 = coordinates[1];
    int x2 = coordinates[2];
    int y2 = coordinates[3];
    int x3 = coordinates[4];
    int y3 = coordinates[5];
    x = (x1+x2+x3)/3;
    y = (y1+y2+y3)/3;

}
