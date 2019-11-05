#ifndef _BARRO_H_
#define _BARRO_H_

#include "Modificador.h"

class Barro: public Modificador {
  public:
    Barro(MundoBox2D *pista, float32 x, float32 y);

    void interactuar(Carro* unCarro);

    bool esValido();

    ~Barro();
};


#endif
