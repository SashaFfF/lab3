 #include "hexagon.h"
#include "shape.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Hexagon::Hexagon(int X, int Y, Shape *parent)
    : Shape(parent)
{
    startX=X;
    startY=Y;
    coordinatesCount = 12;
    coordinates = new int[coordinatesCount];
    coordinates[0]=startX;
    coordinates[1]=startY+50;
    coordinates[2]=startX;
    coordinates[3]=startY+150;
    coordinates[4]=startX+85;
    coordinates[5]=startY+200;
    coordinates[6]=startX+170;
    coordinates[7]=startY+150;
    coordinates[8]=startX+170;
    coordinates[9]=startY+50;
    coordinates[10]=startX+85;
    coordinates[11]=startY;
    Centre(centreX, centreY);
}

void Hexagon::doPainting() {

  QPainter painter(this);

  painter.setPen(QPen(QBrush("#888"), 1));
  painter.setBrush(QBrush(QColor("#888")));

  QPolygon polygon({QPoint(coordinates[0], coordinates[1]),QPoint(coordinates[2], coordinates[3]),
                    QPoint(coordinates[4], coordinates[5]),QPoint(coordinates[6], coordinates[7]),
                    QPoint(coordinates[8], coordinates[9]), QPoint(coordinates[10], coordinates[11])});

  painter.drawPolygon(polygon);

  if (coordinates[0] >= 520){
      killTimer(timerId);
      coordinates[0]=startX;
      coordinates[1]=startY+50;
      coordinates[2]=startX;
      coordinates[3]=startY+150;
      coordinates[4]=startX+85;
      coordinates[5]=startY+200;
      coordinates[6]=startX+170;
      coordinates[7]=startY+150;
      coordinates[8]=startX+170;
      coordinates[9]=startY+50;
      coordinates[10]=startX+85;
      coordinates[11]=startY;
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

double Hexagon::Square(){
    int s1=0;
    int s2=0;
    for (int i =0; i<=8;i+=2){
        s1+=coordinates[i]*coordinates[i+3];
    }
    s1+=coordinates[10]*coordinates[1];
    for (int i=1; i<=9; i+=2){
        s2+=coordinates[i]*coordinates[i+1];
    }
    s2+=coordinates[11]*coordinates[0];
    double S=0.5*abs(s1-s2);
    return S;
}

double Hexagon::Perimeter(){
    double P=0;
    for(int i=0; i<=8; i+=2){
        P+=sqrt(pow(coordinates[i+2]-coordinates[i],2)+pow(coordinates[i+3]-coordinates[i+1],2));
    }
    P+=sqrt(pow(coordinates[0]-coordinates[10],2)+pow(coordinates[1]-coordinates[11],2));
    return P;
}

void Hexagon::Centre(double &x, double &y){
    x=coordinates[0]+0.5*(coordinates[8]-coordinates[0]);
    y=0.5*(coordinates[5]-coordinates[11])+coordinates[11];
}
