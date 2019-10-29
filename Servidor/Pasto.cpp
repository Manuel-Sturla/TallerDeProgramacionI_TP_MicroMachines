#include "Pasto.h"

Pasto::Pasto() {
  id = "Pasto";
  coeficienteDeRozamiento = 0.6f;
}

std::string Pasto::darId() {
  return id;
}

void Pasto::interactuar(Carro* unCarro) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
}

Pasto::~Pasto() {
}
