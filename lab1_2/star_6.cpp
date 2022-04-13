#include "star_6.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>



Star6::Star6(int X, int Y, Shape *parent)
    : Shape(parent)
{
    centreX=X;
    centreY=Y;
    n=6;
    r=60;
    R=90;
    coordinatesCount =4*n;
    coordinates = new int[coordinatesCount];
    int a=90;
    int j=0;
    //Цикл расчета вершин звезды
     for (int i=0;i<n*2;i++)
     {
      if (!(i%2)) //При выполнении условия четности следующие формулы
       {
          coordinates[j]=centreX+r/2*cos(a*M_PI/180);
          coordinates[j+1]=centreY-r/2*sin(a*M_PI/180);
          j+=2;
       }
       else //При невыполнении условия четности следующие формулы
        {
          coordinates[j]=centreX+R*cos(a*M_PI/180);
          coordinates[j+1]=centreY-R*sin(a*M_PI/180);
           j+=2;
        }
        a=a+180/n;
     }
}

double Star6::Square()
{
    return n*r*R*sin(M_PI/n);
}
double Star6::Perimeter()
{
   double P=0;
   for(int i=0; i<4*n-2; i+=2){
       P+=sqrt(pow((coordinates[i+2]-coordinates[i]),2)+pow((coordinates[i+3]-coordinates[i+1]),2));
   }
   return P;
}

void Star6::Centre(double &x, double &y)
{
    x=centreX;
    y=centreY;
}

void Star6::doPainting() {

  QPainter painter(this);

  painter.setPen(QPen(QBrush("#888"), 1));
  painter.setBrush(QBrush(QColor("#888")));

  QPolygon polygon({QPoint(coordinates[0], coordinates[1]),QPoint(coordinates[2], coordinates[3]),
                    QPoint(coordinates[4], coordinates[5]),QPoint(coordinates[6], coordinates[7]),
                    QPoint(coordinates[8], coordinates[9]), QPoint(coordinates[10], coordinates[11]),
                    QPoint(coordinates[12], coordinates[13]),QPoint(coordinates[14], coordinates[15]),
                    QPoint(coordinates[16], coordinates[17]),QPoint(coordinates[18], coordinates[19]),
                    QPoint(coordinates[20], coordinates[21]),QPoint(coordinates[22], coordinates[23])
                    });

  painter.drawPolygon(polygon);
  if (coordinates[0] >= 520){
      killTimer(timerId);
      int a=90;
      int j=0;
       for (int i=0;i<n*2;i++)
       {
        if (!(i%2))
         {
            coordinates[j]=centreX+r/2*cos(a*M_PI/180);
            coordinates[j+1]=centreY-r/2*sin(a*M_PI/180);
            j+=2;
         }
         else
          {
            coordinates[j]=centreX+R*cos(a*M_PI/180);
            coordinates[j+1]=centreY-R*sin(a*M_PI/180);
             j+=2;
          }
          a=a+180/n;
       }
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
