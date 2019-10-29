#include "VelocidadBoost.h"
#include "VelocidadBase.h"
#include <iostream>
#define AUMENTO_VEL 5
VelocidadBoost::VelocidadBoost(float32 velocidadBase) :
EstrategiaDeVelocidad(velocidadBase + AUMENTO_VEL){
  this -> velocidadBase = velocidadBase;
  duracion = 5;
}

std::shared_ptr<EstrategiaDeVelocidad> VelocidadBoost::boost() {
  duracion += 5;
}

std::shared_ptr<EstrategiaDeVelocidad> VelocidadBoost::actualizar() {
  duracion -= 1;
  if (duracion == 0) {
    VelocidadBase nuevaEstrategia(velocidadBase);
    return std::shared_ptr<EstrategiaDeVelocidad> (new VelocidadBase(velocidadBase));
  } else {
    return std::shared_ptr<EstrategiaDeVelocidad>(this);
  }
}
