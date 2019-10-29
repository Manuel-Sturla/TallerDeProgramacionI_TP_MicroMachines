#include "VelocidadBoost.h"
#include "VelocidadBase.h"
#include <iostream>

VelocidadBoost::VelocidadBoost(float32 velocidadBase) {
  this -> velocidadBase = velocidadBase;
  velocidadMaxima = velocidadBase + 5;
  duracion = 5;
}

EstrategiaDeVelocidad VelocidadBoost::boost() {
  duracion += 5;
}

EstrategiaDeVelocidad VelocidadBoost::actualizar() {
  duracion -= 1;
  if (duracion == 0) {
    VelocidadBase nuevaEstrategia(velocidadBase);
    return std::move(nuevaEstrategia);
  } else {
    return *this;
  }
}

bool VelocidadBoost::alcanzoLaVelocidadMaxima(int32 velocidadActual) {
  return  (velocidadActual >= velocidadMaxima);
}
