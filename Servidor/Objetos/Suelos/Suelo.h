#ifndef _SUELO_H_
#define _SUELO_H_

#include "../Interactuable.h"

class Suelo: public Interactuable {
  public:
    virtual void interactuar(Carro *unCarro) = 0;
};

#endif
