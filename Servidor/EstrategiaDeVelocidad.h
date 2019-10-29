#ifndef _ESTRATEGIADEVELOCIDAD_H_
#define _ESTRATEGIADEVELOCIDAD_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"

class EstrategiaDeVelocidad {
  protected:
    float32 velocidadMaxima;
  public:
    virtual EstrategiaDeVelocidad& boost() = 0;

    virtual EstrategiaDeVelocidad& actualizar() = 0;

    virtual bool alcanzoLaVelocidadMaxima(int32 velocidadActual) = 0;
};

#endif
