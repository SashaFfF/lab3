#ifndef STAR_5_H
#define STAR_5_H
#include "shape.h"

class Star5 : public Shape {

  public:
    Star5(int X=0, int Y=0, Shape *parent = 0);
    int n;
    int R;
    int r;

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
  void doPainting() override;
};

#endif // STAR_5_H
