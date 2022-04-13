#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "shape.h"

class Rhombus : public Shape {

  public:
    Rhombus(int X=0, int Y=0, Shape *parent = 0);

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
    void doPainting() override;
};
#endif // RHOMBUS_H
