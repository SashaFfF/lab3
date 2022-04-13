#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape {

  public:
    Rectangle(int X=0, int Y=0, Shape *parent = 0);

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
    void doPainting() override;
};

#endif // RECTANGLE_H
