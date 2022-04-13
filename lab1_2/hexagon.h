#ifndef HEXAGON_H
#define HEXAGON_H
#include "shape.h"

class Hexagon : public Shape {

  public:
    Hexagon(int X=0, int Y=0, Shape *parent = 0);

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
    void doPainting() override;
};

#endif // HEXAGON_H
