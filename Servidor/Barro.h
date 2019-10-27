#ifndef _BARRO_H_
#define _BARRO_H_

#include "Modificador.h"

class Barro: public Modificador {
  public:
    std::string darId();

    void interactuar(Carro* unCarro);
};


#endif
