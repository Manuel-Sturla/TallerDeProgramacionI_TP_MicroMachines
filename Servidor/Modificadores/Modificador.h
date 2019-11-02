#ifndef _MODIFICADOR_H_
#define _MODIFICADOR_H_

#include "../Interactuable.h"
#include "../Carro/Carro.h"

class Modificador: public Interactuable {
  protected:
    bool validez;
    b2Body* cuerpo;
  public:
    std::string darId();
};

#endif