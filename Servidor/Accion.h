#ifndef _ACCION_H_
#define _ACCION_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "EstrategiaDeVelocidad.h"

class Accion {
  protected:
    void aplicarFuerza(b2Body* body, float32 factorDeFuerza);

  public:
    virtual void ejecutar(b2Body* body, std::shared_ptr<EstrategiaDeVelocidad> estrategiaDeVelocidad, float32 angulo) = 0;
};


#endif
