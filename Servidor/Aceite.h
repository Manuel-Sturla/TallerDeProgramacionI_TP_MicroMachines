#ifndef _ACEITE_H_
#define _ACEITE_H_

#include "Modificador.h"

class Aceite: public Modificador {
  public:
    std::string darId();

    void interactuar(Carro* unCarro);
};


#endif
