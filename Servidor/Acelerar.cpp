#include "Acelerar.h"

void Acelerar::ejecutar(b2Body *body, EstrategiaDeVelocidad *estrategiaDeVelocidad, float32 angulo) {
  b2Vec2 velocidad = body -> GetLinearVelocity();
  if (!estrategiaDeVelocidad -> alcanzoLaVelocidadMaxima()) {
    aplicarFuerza(body, 100.0f);
  }
}
