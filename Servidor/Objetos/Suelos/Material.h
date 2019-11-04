#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <iostream>
#include "Box2D/Box2D.h"
#include "../Carro/Carro.h"

class Material {
  protected:
    std::string id;
    float32 coeficienteDeRozamiento;
  public:
    virtual void interactuar(Carro* unCarro) = 0;

    void empaquetarMaterial(std::vector<std::string> *destino);
};

#endif
