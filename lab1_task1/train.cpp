#include "train.h"
#include "rectangle.h"
#include <QPainter>
#include <QTimer>
#include <QGridLayout>

Train::Train(Rectangle *parent)
    : Rectangle(parent)
{

}

void Train::doPainting() {
    if (startX >= 520){
        killTimer(timerId);
        startX = 50;

    }
  QPainter painter(this);

  painter.setPen(QColor("#0509b5"));

  painter.setBrush(QBrush("#0509b5"));
  painter.drawRect(startX, 200, 255, 90);

  painter.setBrush(QBrush("#0509b5"));
  painter.drawRect(startX, 130, 100, 70);

  painter.setPen(QColor("#785f36"));

  painter.setBrush(QBrush("#785f36"));
  painter.drawRect(startX + 170, 140, 30, 60);

  painter.setPen(QPen(QBrush("#70876f"), 1));
  painter.setBrush(QBrush(QColor("#70876f")));

  painter.drawEllipse(startX-25, 250, 75, 75);
  painter.drawEllipse(startX+50, 250, 75, 75);

  painter.drawEllipse(startX+155, 275, 55, 55);
  painter.drawEllipse(startX+210, 275, 55, 55);

  painter.setPen(QPen(QBrush("#b0bccf"), 1));
  painter.setBrush(QBrush(QColor("#b0bccf")));

  painter.drawEllipse(startX+155, 100, 60, 30);
  painter.drawEllipse(startX+100, 65, 75, 35);
  painter.drawEllipse(startX+10, 30, 95, 45);



}




