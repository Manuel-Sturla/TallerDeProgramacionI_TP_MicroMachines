#include "Pasto.h"

Pasto::Pasto() {
  coeficienteDeRozamiento = 0.6f;
}

void Pasto::interactuar(Carro* unCarro) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
}

Pasto::~Pasto() {
}
