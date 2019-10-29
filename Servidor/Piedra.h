#ifndef _PIEDRA_H_
#define _PIEDRA_H_

#include "Modificador.h"
#include "Pista.h"

class Piedra: public Modificador {
  private:
    b2Body* cuerpo;
    Pista *pista;
    bool validez;

  public:
    Piedra(Pista *pista);

    std::string darId();

    void interactuar(Carro* unCarro);

    bool esValido();

    ~Piedra();
};


#endif
