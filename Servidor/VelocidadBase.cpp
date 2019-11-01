#include "VelocidadBase.h"
#include <iostream>

VelocidadBase::VelocidadBase(float32 velocidadMaxima):
    Velocidad(velocidadMaxima){
}

std::string VelocidadBase::actualizar() {
  return "Base";
}

std::string VelocidadBase::boost() {
  return "Boost";
}
