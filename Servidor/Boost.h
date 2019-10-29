#ifndef _BOOST_H_
#define _BOOST_H_

#include "Modificador.h"

class Boost: public Modificador {
  private:
    b2Body* cuerpo;
    Pista *pista;
    bool validez;
  public:
    Boost(Pista *pista);

    std::string darId();

    bool esValido();

    void interactuar(Carro* unCarro);

    ~Boost();
};


#endif
