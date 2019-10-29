#ifndef _LIMITEDEPISTA_H_
#define _LIMITEDEPISTA_H_

#include "Material.h"

class LimiteDePista: public Material {
  public:
    LimiteDePista();

    std::string darId();

    void interactuar(Carro* unCarro);

    ~LimiteDePista();
};


#endif
