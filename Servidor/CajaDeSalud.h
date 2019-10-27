#ifndef _CAJADESALUD_H_
#define _CAJADESALUD_H_

#include "Modificador.h"

class CajaDeSalud: Modificador {
  public:
    std::string darId();

    void interactuar(Carro* unCarro);
};


#endif
