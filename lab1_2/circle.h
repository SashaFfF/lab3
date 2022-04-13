#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle: public Shape {

  public:
    Circle(int X = 0, int Y = 0, Shape *parent = 0);
    int R;
    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;
    void Scale(int delta) override;


  private:
    void doPainting() override;
};

#endif // CIRCLE_H
