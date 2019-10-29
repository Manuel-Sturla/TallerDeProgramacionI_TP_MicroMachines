#ifndef _VELOCIDADBASE_H_
#define _VELOCIDADBASE_H_

#include "EstrategiaDeVelocidad.h"

class VelocidadBase: public EstrategiaDeVelocidad {
  public:
    VelocidadBase(float32 velocidadMaxima);

    EstrategiaDeVelocidad boost();

    EstrategiaDeVelocidad actualizar();

    bool alcanzoLaVelocidadMaxima();
};


#endif
