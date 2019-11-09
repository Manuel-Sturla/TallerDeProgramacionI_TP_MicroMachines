#ifndef _PASTO_H_
#define _PASTO_H_

#include "Material.h"

class Pasto: public Material {
  public:
    Pasto();

    void interactuar(Carro *unCarro, int numeroDeSuelo);

    ~Pasto();
};


#endif
