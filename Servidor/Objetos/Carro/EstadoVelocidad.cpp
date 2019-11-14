#include "EstadoVelocidad.h"

EstadoVelocidad::EstadoVelocidad(float32 velocidadMaxima): velocidadBase(velocidadMaxima),
velocidadBoost(velocidadMaxima) {
  estados["Base"] = &velocidadBase;
  estados["Boost"] = &velocidadBoost;
  estadoActual = "Base";
}

void EstadoVelocidad::boost() {
  estadoActual = estados[estadoActual] -> boost();
}

bool EstadoVelocidad::alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual) {
  return estados[estadoActual] -> alcanzoLaVelocidadMaxima(velocidadActual);
}

void EstadoVelocidad::actualizar(b2Body *cuerpo) {
  estadoActual = estados[estadoActual] -> actualizar();
}

EstadoVelocidad::~EstadoVelocidad() {
}

void EstadoVelocidad::acelerar(b2Body *cuerpo) {
    b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
    if (!alcanzoLaVelocidadMaxima(velocidad)) {
        aplicarFuerza(cuerpo, 5*0.2);
    }
}

void EstadoVelocidad::aplicarFuerza(b2Body *cuerpo, float32 factorDeFuerza) {
    float32 angulo = cuerpo->GetAngle();
    b2Vec2 fuerza(factorDeFuerza * cos(angulo), factorDeFuerza * sin(angulo));
    cuerpo -> ApplyLinearImpulseToCenter(fuerza, true);
}

void EstadoVelocidad::frenar(b2Body *cuerpo) {
    b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
    if (!alcanzoLaVelocidadMaxima(velocidad)) {
        aplicarFuerza(cuerpo, -5*0.2);
    }
}
