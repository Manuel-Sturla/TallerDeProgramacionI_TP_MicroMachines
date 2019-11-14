#ifndef _BOOST_H_
#define _BOOST_H_

#include "Modificador.h"

class Boost: public Modificador {
  public:
    Boost(MundoBox2D &pista, float32 x, float32 y, unsigned long id);

    bool esValido();

    void interactuar(Carro* unCarro);

    ~Boost();
};


#endif
