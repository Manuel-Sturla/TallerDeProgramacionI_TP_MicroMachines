#include "Agarre.h"

Agarre::Agarre(float agarre) {
  agarreBase = agarre;
  duracion = 0;
  agarreReducido = false;
}

void Agarre::actualizar(b2Body &cuerpo) {
  float32 nuevaVelocidadAngular = (1 / agarreBase) * cuerpo.GetAngularVelocity();
  cuerpo.SetAngularVelocity(nuevaVelocidadAngular); //Esto esta mal, aplicar torques
  if (agarreReducido) {
    actualizarAgarreReducido();
  }
}

void Agarre::reducirAgarre() {
  agarreReducido = true;
  duracion += 5;
}

void Agarre::actualizarAgarreReducido() {
  duracion -= 1;
  if (duracion == 0) {
    agarreReducido = false;
  }
}

Agarre::~Agarre() {
}

void Agarre::obtenerDatos(CarroDTO &dto) {
    dto.agarreBase = agarreBase;
    dto.agarreReducido = agarreReducido;
    dto.duracionAgarreReducido = duracion;
}

void Agarre::actualizarDatos(CarroDTO_t &dto) {
    agarreBase = dto.agarreBase;
    agarreReducido = dto.agarreReducido;
    duracion = dto.duracionAgarreReducido;
}
