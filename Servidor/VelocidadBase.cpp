#include "VelocidadBase.h"
#include "VelocidadBoost.h"
#include <iostream>

VelocidadBase::VelocidadBase(float32 velocidadMaxima) {
  this -> velocidadMaxima = velocidadMaxima;
}

EstrategiaDeVelocidad VelocidadBase::actualizar() {
  return *this;
}

EstrategiaDeVelocidad VelocidadBase::boost() {
  VelocidadBoost velocidadBoost(velocidadMaxima);
  return std::move(velocidadBoost);
}

bool VelocidadBase::alcanzoLaVelocidadMaxima(int32 velocidadActual) {
  return  (velocidadActual >= velocidadMaxima);
}
