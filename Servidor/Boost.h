#ifndef _BOOST_H_
#define _BOOST_H_

#include "Modificador.h"

class Boost: public Modificador {
  private:
    b2Body* cuerpo;
    Pista *pista;
  public:
    Boost(Pista *pista);

    std::string darId();

    void interactuar(Carro* unCarro);

    ~Boost();
};


#endif
