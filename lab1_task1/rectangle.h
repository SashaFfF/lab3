#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QWidget>
#include <QPushButton>

class Rectangle : public QWidget {

 public:
   Rectangle(QWidget *parent = 0);
   void stop();
   void start();


 protected:
   int startX;
   int timerId;

   void paintEvent(QPaintEvent *e);
   void timerEvent(QTimerEvent *e);
   virtual void doPainting();

};
#endif //RECTANGLE_H
