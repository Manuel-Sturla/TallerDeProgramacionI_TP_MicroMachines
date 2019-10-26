#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Interactuable.h"
#include <iostream>
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"

class Material: public Interactuable {
  protected:
    float32 coeficienteDeRozamiento;
};

#endif
