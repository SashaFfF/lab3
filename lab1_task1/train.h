#ifndef TRAIN_H
#define TRAIN_H
#include "rectangle.h"

class Train : public Rectangle {

  public:
    Train(Rectangle *parent = 0);

  private:
    void doPainting() override;


};
#endif // TRAIN_H
