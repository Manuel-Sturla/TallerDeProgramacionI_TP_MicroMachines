#include "VelocidadBoost.h"
#include "VelocidadBase.h"
#include <iostream>
#define AUMENTO_VEL 5
#define DURACION_INICIAL 5
VelocidadBoost::VelocidadBoost(float32 velocidadBase) :
EstrategiaDeVelocidad(velocidadBase + AUMENTO_VEL){
  this -> velocidadBase = velocidadBase;
  duracion = DURACION_INICIAL;
}

std::shared_ptr<EstrategiaDeVelocidad> VelocidadBoost::boost() {
  duracion += DURACION_INICIAL;
  return std::shared_ptr<EstrategiaDeVelocidad>(this);
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
