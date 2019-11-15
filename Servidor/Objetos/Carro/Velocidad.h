#ifndef _VELOCIDAD_H_
#define _VELOCIDAD_H_

#include "Box2D/Box2D.h"
#include <string>

class Velocidad {
  protected:
    float32 velocidadMaxima;
    float32 aceleracion;
  public:
    Velocidad(float32 velocidadMaxima, float32 aceleracion);

    virtual std::string boost() = 0;

    virtual std::string actualizar() = 0;

    float32 darImpulso();

    bool alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual);
};

#endif
