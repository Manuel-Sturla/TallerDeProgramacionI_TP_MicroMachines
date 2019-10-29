#ifndef _ESTRATEGIADEVELOCIDAD_H_
#define _ESTRATEGIADEVELOCIDAD_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"

class EstrategiaDeVelocidad {
  protected:
    float32 velocidadMaxima;
  public:
    EstrategiaDeVelocidad(float32 velocidadMaxima);
    virtual std::shared_ptr<EstrategiaDeVelocidad> boost() = 0;

    virtual std::shared_ptr<EstrategiaDeVelocidad> actualizar() = 0;

    bool alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual);
};

#endif
