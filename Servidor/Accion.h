#ifndef _ACCION_H_
#define _ACCION_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"

class Accion {
  protected:
    void aplicarFuerza(b2Body* body, float32 factorDeFuerza);

  public:
    virtual void ejecutar(b2Body* body, float32 velocidadMax) = 0;
};


#endif
