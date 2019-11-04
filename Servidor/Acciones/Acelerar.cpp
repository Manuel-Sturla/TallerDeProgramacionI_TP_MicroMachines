#include "Acelerar.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

void Acelerar::ejecutar(b2Body *body, EstadoVelocidad *estadoVelocidad, float32 angulo) {
  b2Vec2 velocidad = body -> GetLinearVelocity();
  if (!estadoVelocidad -> alcanzoLaVelocidadMaxima(velocidad)) {
    aplicarFuerza(body, 100.0f);
  }
}
