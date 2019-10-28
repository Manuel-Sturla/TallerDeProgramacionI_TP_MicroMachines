#include "Acelerar.h"

void Acelerar::ejecutar(b2Body *body, float32 velocidadMax, float32 angulo) {
  b2Vec2 velocidad = body -> GetLinearVelocity();
  if (velocidad.Length() < velocidadMax) {
    aplicarFuerza(body, 100.0f);
  }
}
