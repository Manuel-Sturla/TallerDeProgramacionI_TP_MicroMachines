#ifndef _LIMITEDEPISTA_H_
#define _LIMITEDEPISTA_H_

#include "Material.h"

class LimiteDePista: public Material {
  public:
    LimiteDePista();

    void interactuar(Carro *unCarro, int numeroDeSuelo);

    ~LimiteDePista();
};


#endif
