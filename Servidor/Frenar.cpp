#include "Frenar.h"

void Frenar::ejecutar(b2Body *body, float32 velocidadMax) {
  b2Vec2 velocidad = body -> GetLinearVelocity();
  if (velocidad.Length() <= velocidadMax) {
    aplicarFuerza(body, -100.0f);
  }
}
