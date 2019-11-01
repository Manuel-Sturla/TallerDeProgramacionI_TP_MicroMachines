#ifndef _ASFALTO_H_
#define _ASFALTO_H_

#include "Material.h"
#include "Carro.h"

class Asfalto: public Material {
  public:
    Asfalto();

    void interactuar(Carro* unCarro) override;

    ~Asfalto();

};


#endif
