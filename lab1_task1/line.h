#ifndef LINE_H
#define LINE_H
#include <QWidget>

class Line: public QWidget {

 public:
   Line(double X);
   void stop();
   void start();
   void startRotate();
   double x1;
   double x2;
   double y1;
   double y2;



 protected:
   double startX;
   int timerId;

   void paintEvent(QPaintEvent *e);
   void timerEvent(QTimerEvent *e);
   void doPainting();
   void Rotate(double angle);
   void Center(double &center_x,double &center_y);


};

#endif // LINE_H
