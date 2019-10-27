#ifndef _PIEDRA_H_
#define _PIEDRA_H_

#include "Modificador.h"

class Piedra: public Modificador {
  public:
    std::string darId();

    void interactuar(Carro* unCarro);
};


#endif
