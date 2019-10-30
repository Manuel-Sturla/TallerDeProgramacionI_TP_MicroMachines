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

void EstadoVelocidad::actualizar() {
  estadoActual = estados[estadoActual] -> actualizar();
}

EstadoVelocidad::~EstadoVelocidad() {
}
