#ifndef _ESTADOVELOCIDAD_H_
#define _ESTADOVELOCIDAD_H_

#include <string>
#include <unordered_map>
#include "Velocidad.h"
#include "VelocidadBase.h"
#include "VelocidadBoost.h"
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"

class EstadoVelocidad {
  private:
    VelocidadBase velocidadBase;
    VelocidadBoost velocidadBoost;
    std::unordered_map<std::string, Velocidad*> estados;
    std::string estadoActual;
  public:
    explicit EstadoVelocidad(float32 velocidadMaxima);

    void boost();

    void actualizar(b2Body *cuerpo);

    bool alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual);

    ~EstadoVelocidad();
};


#endif
