#ifndef _PASTO_H_
#define _PASTO_H_

#include "Material.h"

class Pasto: public Material {
  public:
    Pasto();

    std::string darId();

    void interactuar(Carro* unCarro);

    bool esValido();

    ~Pasto();
};


#endif
