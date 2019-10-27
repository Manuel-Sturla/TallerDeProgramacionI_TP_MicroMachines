#ifndef _BOOST_H_
#define _BOOST_H_

#include "Modificador.h"

class Boost: public Modificador {
  public:
    std::string darId();

    void interactuar(Carro* unCarro);
};


#endif
