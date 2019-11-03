#include "Pasto.h"

Pasto::Pasto() {
  coeficienteDeRozamiento = 0.6f;
  id = "Pasto";
}

void Pasto::interactuar(Carro* unCarro) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
}

Pasto::~Pasto() {
}
