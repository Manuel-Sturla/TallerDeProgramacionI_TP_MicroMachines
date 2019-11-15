#include "VelocidadBase.h"
#include <iostream>

VelocidadBase::VelocidadBase(float32 velocidadMaxima, float32 aceleracion) :
    Velocidad(velocidadMaxima, aceleracion) {
}

std::string VelocidadBase::actualizar() {
  return "Base";
}

std::string VelocidadBase::boost() {
  return "Boost";
}
