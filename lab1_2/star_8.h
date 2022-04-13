#ifndef STAR_8_H
#define STAR_8_H
#include "shape.h"

class Star8 : public Shape {

  public:
    Star8(int X = 0, int Y = 0, Shape *parent = 0);
    int n;
    int R;
    int r;

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;

  private:
  void doPainting() override;
};

#endif // STAR_8_H
