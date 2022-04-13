#include "rectangle.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Rectangle::Rectangle(QWidget *parent)
    : QWidget(parent)
{
    startX = 50;
}
void Rectangle::stop() {
    killTimer(timerId);
}

void Rectangle::start() {
    timerId = startTimer(25);
}

void Rectangle::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);
  doPainting();
}

void Rectangle::doPainting() {
  QPainter painter(this);

  painter.setPen(QColor("#0509b5"));

  painter.setBrush(QBrush("#0509b5"));
  painter.drawRect(startX, 200, 255, 90);

  if (startX >= 520){
      //killTimer(timerId);
      startX = 50;
  }
}


void Rectangle::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);
    startX += 5;
    repaint();
}

