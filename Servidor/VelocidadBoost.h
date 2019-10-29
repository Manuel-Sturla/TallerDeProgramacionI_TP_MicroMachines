#ifndef _VELOCIDADBOOST_H_
#define _VELOCIDADBOOST_H_

#include "EstrategiaDeVelocidad.h"

class VelocidadBoost: public EstrategiaDeVelocidad {
  private:
    float32 velocidadBase;
    int32 duracion;
  public:
    VelocidadBoost(float32 velocidadBase);

    EstrategiaDeVelocidad boost();

    EstrategiaDeVelocidad actualizar();

    bool alcanzoLaVelocidadMaxima(int32 velocidadActual);
};


#endif
