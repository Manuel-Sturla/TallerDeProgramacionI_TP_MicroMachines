#include "Acelerar.h"

void Acelerar::ejecutar(b2Body *body, std::shared_ptr<EstrategiaDeVelocidad> estrategiaDeVelocidad, float32 angulo) {
  b2Vec2 velocidad = body -> GetLinearVelocity();
  if (!estrategiaDeVelocidad -> alcanzoLaVelocidadMaxima(velocidad)) {
    aplicarFuerza(body, 100.0f);
  }
}
