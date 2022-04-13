#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square2: public Shape {

  public:
    Square2(int X = 0, int Y = 0, Shape *parent = 0);

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
    void doPainting() override;
};

#endif // SQUARE_H
