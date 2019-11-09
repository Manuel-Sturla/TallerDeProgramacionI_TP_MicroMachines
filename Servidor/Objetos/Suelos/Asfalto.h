#ifndef _ASFALTO_H_
#define _ASFALTO_H_

#include "Material.h"
#include "../Carro/Carro.h"

class Asfalto: public Material {
  public:
    Asfalto();

    void interactuar(Carro *unCarro, int numeroDeSuelo) override;

    ~Asfalto();

};


#endif
