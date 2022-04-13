#include "semicircle.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Semicircle::Semicircle(int X, int Y, Circle *parent)
    :Circle(X, Y, parent)
{
    startX=X;
    startY=Y;
    coordinates[0]=startX;
    coordinates[1]=startY;
    R=200;
    Centre(centreX, centreY);
}

void Semicircle::doPainting() {

  QPainter painter(this);

  painter.setPen(QPen(QBrush("#888"), 1));
  painter.setBrush(QBrush(QColor("#888")));

  painter.drawChord(coordinates[0], coordinates[1], R, R, 0, 16*180);

  if (coordinates[0] >= 520){
      killTimer(timerId);
      coordinates[0]=startX;
      coordinates[1]=startY;
      R=200;
  }

  if(scaleDelta <= 0){
      killTimer(scaleTimerId);
      scaleTimerId = -1;
  }
}

double Semicircle::Square(){
    double p=3.1415;
    double S=0.5*p*pow(R,2);
    return S;
}

double Semicircle::Perimeter(){
    double p=3.1415;
    double P=p*R+2*R;
    return P;
}

void Semicircle::Centre(double &x, double &y){
    x=coordinates[0]+R;
    y=coordinates[1]+R;
}


