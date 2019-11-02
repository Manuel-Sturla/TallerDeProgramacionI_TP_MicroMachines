#ifndef _ACELERAR_H_
#define _ACELERAR_H_

#include "Accion.h"
#include "../Carro/EstadoVelocidad.h"

class Acelerar: public Accion {
  public:
    void ejecutar(b2Body* body, EstadoVelocidad *estadoVelocidad, float32 angulo);
};

#endif
