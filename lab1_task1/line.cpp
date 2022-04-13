#include "line.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>

Line::Line(double X)
{
    startX=X;
    x1=startX-25.0;
    x2=startX+50.0;
    y1=287.0;
    y2=287.0;
}

void Line::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);
  doPainting();
}

void Line::doPainting() {
    if ((x2 >= 505+startX) || (x1 >= 505+startX)){
        killTimer(timerId);
        x1=startX-25.0;
        x2=startX+50.0;
        y1=287.0;
        y2=287.0;
    }
    QPainter painter(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(x1, y1, x2, y2);

}

void Line::stop() {
    killTimer(timerId);
}

void Line::start() {
    timerId = startTimer(25);
}

void Line::timerEvent(QTimerEvent *e) {

  Q_UNUSED(e);

  x1+=5.0;
  x2+=5.0;
  Rotate(45.0);
  repaint();
}

void Line::Center(double &center_x, double &center_y){
    if(x1==x2){
        center_x=x1;
    }
    else {
        if (x1 < x2) {
            center_x= x1 + 0.5*(x2-x1);
        } else {
            center_x= x2 + 0.5*(x1-x2);
        }
    }
    if(y1==y2){
        center_y=y1;
    }
    else {
        if (y1 < y2) {
            center_y= y1 + 0.5*(y2-y1);
        } else {
            center_y= y2 + 0.5*(y1-y2);
        }
    }
}

void Line::Rotate(double angle) {
    double PI = 3.1415;
    double x = 0;
    double y = 0;
    Center(x, y);
        // вычитаю из каждой точки центр
        x1 -= x;
        y1 -= y;

        // поворачиваю точку по формулам:
        // xNew = x * Cos(A) + y * Sin(A)
        // yNew = y * Cos(A) - x * Sin(A)
        // angle - подаётся в градусах, поэтому конвертирую в радианы

        double new_x = cos(angle * (PI / 180.0))*x1 - sin(angle * (PI / 180.0)) * y1;
        double new_y = sin(angle * (PI / 180.0)) *x1 + cos(angle * (PI / 180.0))*y1;

        // прибавляю к повернутой точке центр прямоугольника и записываю обратно в массив
        x1 = x + new_x;
        y1 = y + new_y;

        x2 -= x;
        y2 -= y;

        new_x = cos(angle * (PI / 180.0))*x2 - sin(angle * (PI / 180.0)) * y2;
        new_y = sin(angle * (PI / 180.0)) *x2 + cos(angle * (PI / 180.0))*y2;

        x2 = x + new_x;
        y2 = y + new_y;

}
