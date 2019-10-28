#ifndef _GIROAIZQUIERDA_H_
#define _GIROAIZQUIERDA_H_

#include "Accion.h"

class GiroAIzquierda: public Accion {
  public:
    void ejecutar(b2Body* body, float32 velocidadMax, float32 angulo);
};


#endif
