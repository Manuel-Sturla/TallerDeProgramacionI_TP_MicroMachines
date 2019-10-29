#ifndef _BARRO_H_
#define _BARRO_H_

#include "Modificador.h"

class Barro: public Modificador {
  protected:
    b2Body* cuerpo;
    Pista *pista;
  public:
    Barro(Pista *pista);

    std::string darId();

    void interactuar(Carro* unCarro);

    ~Barro();
};


#endif
