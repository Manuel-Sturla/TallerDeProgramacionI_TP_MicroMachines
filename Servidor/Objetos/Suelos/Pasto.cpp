#include "Pasto.h"

Pasto::Pasto() {
  coeficienteDeRozamiento = 4.0f;
  id = "Pasto";
}

void Pasto::interactuar(Carro* unCarro) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
}

Pasto::~Pasto() {
}
