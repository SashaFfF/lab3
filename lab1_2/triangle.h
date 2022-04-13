#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape {

  public:
    Triangle(int X = 0, int Y = 0, Shape *parent = 0);

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
    void doPainting() override;
};
#endif // TRIANGLE_H
