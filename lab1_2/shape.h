#ifndef SHAPE_H
#define SHAPE_H
#include <QWidget>
#include <QColor>
#include <QPushButton>

class Shape : public QWidget {

 public:
   Shape(QWidget *parent = 0, int X = 0, int Y = 0);
   int startX;
   int startY;
   void stop();
   void start();
   void startScale();
   void startRotate();
   virtual double Square();
   virtual double Perimeter();
   virtual void Centre(double& x, double& y);
   virtual void Scale(int delta);
   virtual void Rotate(double angle);


 protected:
   int *coordinates;
   double centreX, centreY;
   int coordinatesCount;
   int timerId;
   int scaleTimerId;
   int rotateTimerId;
   int scaleDelta;
   int rotateAngle;


   void paintEvent(QPaintEvent *e);
   void timerEvent(QTimerEvent *e);
   virtual void doPainting();
};
   #endif // SHAPE_H
