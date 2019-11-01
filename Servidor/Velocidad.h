#ifndef _VELOCIDAD_H_
#define _VELOCIDAD_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include <string>

class Velocidad {
  protected:
    float32 velocidadMaxima;
  public:
    Velocidad(float32 velocidadMaxima);

    virtual std::string boost() = 0;

    virtual std::string actualizar() = 0;

    bool alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual);
};

#endif
