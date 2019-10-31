#ifndef _PIEDRA_H_
#define _PIEDRA_H_

#include "Modificador.h"
#include "Pista.h"

class Piedra: public Modificador {
  public:
    Piedra(Pista *pista, float32 x, float32 y);

    void interactuar(Carro* unCarro);

    bool esValido();

    ~Piedra();
};


#endif
