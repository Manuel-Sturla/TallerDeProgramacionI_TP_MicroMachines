#ifndef _GIROAIZQUIERDA_H_
#define _GIROAIZQUIERDA_H_

#include "Accion.h"

class GiroAIzquierda: public Accion {
  public:
    void ejecutar(b2Body* body, std::shared_ptr<EstrategiaDeVelocidad> estrategiaDeVelocidad, float32 angulo);
};


#endif
