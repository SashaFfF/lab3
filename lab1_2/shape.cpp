#include "shape.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>
#include <QDebug>
#include "mainwindow.h"


Shape::Shape(QWidget *parent, int X, int Y)
    : QWidget(parent)
{
    startX=X;
    startY=Y;
    timerId = -1;
    scaleTimerId = -1;
    rotateTimerId = -1;
    coordinatesCount = 2;
    coordinates = new int [coordinatesCount];
    coordinates[0] = startX-50;
    coordinates[1]= startY+100;
    scaleDelta = 25;
    rotateAngle = 0;
}

void Shape::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);
  doPainting();
}

void Shape::doPainting() {

}

void Shape::stop() {
    killTimer(timerId);
    timerId = -1;
}

void Shape::start() {
    timerId = startTimer(25);
}

void Shape::startScale(){
    scaleTimerId = startTimer(25);
}

void Shape::startRotate(){
    rotateTimerId = startTimer(35);
}

void Shape::timerEvent(QTimerEvent *e) {

  Q_UNUSED(e);

  if (timerId != -1){
      for (int i = 0; i < coordinatesCount; i += 2){
          coordinates[i] += 5;
      }
      repaint();
  }

  if (scaleTimerId != -1){
      Scale(5);
      repaint();
      scaleDelta -= 5;
  }

  if (rotateTimerId != -1){
      Rotate(45.0);
      repaint();
      rotateAngle += 45;
  }
}

double Shape::Square(){
    return 0;
}

double Shape::Perimeter(){
    return 0;
}

void Shape::Centre(double& x, double& y){
    x=0;
    y=0;
}

void Shape::Scale(int delta){
    double x, y;
    Centre(x,y);

    for (int i = 0; i < coordinatesCount; i += 2){
        if (coordinates[i] > x) {
            coordinates[i] += delta;
        }
        if (coordinates[i] < x) {
            coordinates[i] -= delta;
        }
    }

    for (int i = 1; i < coordinatesCount; i += 2){
        if (coordinates[i] > y) {
            coordinates[i] += delta;
        }
        if (coordinates[i] < y) {
            coordinates[i] -= delta;
        }

    }
}

void Shape::Rotate(double angle) {
    double PI = 3.1415;
    double x = centreX;
    double y = centreY;

    for (int i = 0; i < coordinatesCount; i += 2){
        // вычитаю из каждой точки центр
        coordinates[i] -= x;
        coordinates[i+1] -= y;

        // поворачиваю точку по формулам:
        // xNew = x * Cos(A) + y * Sin(A)
        // yNew = y * Cos(A) - x * Sin(A)
        // angle - подаётся в градусах, поэтому конвертирую в радианы

        int new_x = cos(angle * (PI / 180.0))*coordinates[i] - sin(angle * (PI / 180.0)) * coordinates[i+1];
        int new_y = sin(angle * (PI / 180.0)) * coordinates[i] + cos(angle * (PI / 180.0))*coordinates[i+1];

        // прибавляю к повернутой точке центр прямоугольника и записываю обратно в массив
        coordinates[i] = x + new_x;
        coordinates[i+1] = y + new_y;
    }
}



