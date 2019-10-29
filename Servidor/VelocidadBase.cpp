#include "VelocidadBase.h"
#include "VelocidadBoost.h"
#include <iostream>

VelocidadBase::VelocidadBase(float32 velocidadMaxima):
EstrategiaDeVelocidad(velocidadMaxima){
}

std::shared_ptr<EstrategiaDeVelocidad> VelocidadBase::actualizar() {
  return std::shared_ptr<EstrategiaDeVelocidad> (this);
}

std::shared_ptr<EstrategiaDeVelocidad> VelocidadBase::boost() {
  return std::shared_ptr<EstrategiaDeVelocidad> (new VelocidadBoost(velocidadMaxima));
}
