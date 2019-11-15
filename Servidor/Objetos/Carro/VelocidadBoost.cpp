#include "VelocidadBoost.h"
#include <iostream>
#define AUMENTO_VEL 5
#define DURACION_INICIAL 5

VelocidadBoost::VelocidadBoost(float32 velocidadBase, float32 aceleracion) :
    Velocidad(velocidadBase + AUMENTO_VEL, aceleracion) {
  duracion = DURACION_INICIAL;
}

std::string VelocidadBoost::boost() {
  duracion += DURACION_INICIAL;
  return "Boost";
}

std::string VelocidadBoost::actualizar() {
  duracion -= 1;
  if (duracion == 0) {
    duracion = DURACION_INICIAL;
    return "Base";
  } else {
    return "Boost";
  }
}
