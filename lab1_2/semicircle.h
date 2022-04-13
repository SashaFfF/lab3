#ifndef SEMICIRCLE_H
#define SEMICIRCLE_H
#include "circle.h"

class Semicircle : public Circle {

  public:
    Semicircle(int X = 0, int Y = 0, Circle *parent = 0);
    double Square() override;
    double Perimeter() override;
    void Centre(double& x, double& y) override;


  private:
    void doPainting() override;
};
#endif // SEMICIRCLE_H
