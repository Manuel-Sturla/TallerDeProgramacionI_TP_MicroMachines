#ifndef _ESTADOVELOCIDAD_H_
#define _ESTADOVELOCIDAD_H_

#include <string>
#include <unordered_map>
#include "Velocidad.h"
#include "VelocidadBase.h"
#include "VelocidadBoost.h"
#include "Box2D/Box2D.h"

class EstadoVelocidad {
  private:
    VelocidadBase velocidadBase;
    VelocidadBoost velocidadBoost;
    std::unordered_map<std::string, Velocidad*> estados;
    std::string estadoActual;

    void aplicarFuerza(b2Body &cuerpo, float32 factorDeFuerza);
  public:
    explicit EstadoVelocidad(float32 velocidadMaxima, float32 aceleracion);

    void acelerar(b2Body &cuerpo);

    void frenar(b2Body &cuerpo);

    void boost();

    void actualizar();

    bool alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual);

    ~EstadoVelocidad();
};


#endif
