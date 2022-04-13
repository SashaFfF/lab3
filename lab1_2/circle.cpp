#include "circle.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Circle::Circle(int X, int Y, Shape *parent)
    : Shape(parent)
{
    startX = X;
    startY = Y;
    coordinatesCount = 2;
    coordinates = new int[coordinatesCount];
    coordinates[0]=startX;
    coordinates[1]=startY;
    R=80;
    Centre(centreX, centreY);
}

void Circle::doPainting() {

  QPainter painter(this);

  painter.setPen(QPen(QBrush("#888"), 1));
  painter.setBrush(QBrush(QColor("#888")));

  painter.drawEllipse(coordinates[0], coordinates[1], R, R);

  if (coordinates[0] >= 520){
      killTimer(timerId);
      coordinates[0]=150;
      coordinates[1]=200;
      R=80;
  }

  if(scaleDelta <= 0){
      killTimer(scaleTimerId);
      scaleTimerId = -1;
  }
}

double Circle::Square(){
    double p=3.1415;
    double S=p*pow(R,2);
    return S;
}

double Circle::Perimeter(){
    double p=3.1415;
    double P=2*p*R;
    return P;
}

void Circle::Centre(double &x, double &y){
    x=coordinates[0] + R;
    y=coordinates[1] - R;
}

void Circle::Scale(int delta){
    coordinates[0] -= delta/2;
    coordinates[1] -= delta;
    R += delta;
}
