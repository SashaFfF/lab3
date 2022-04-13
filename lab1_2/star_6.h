#ifndef STAR_6_H
#define STAR_6_H
#include "shape.h"

class Star6 : public Shape {

  public:
    Star6(int X=0, int Y=0, Shape *parent = 0);
    int n;
    int R;
    int r;

    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
  void doPainting() override;
};
#endif // STAR_6_H
