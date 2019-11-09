#include "Pasto.h"

Pasto::Pasto() {
  coeficienteDeRozamiento = 4.0f;
  id = "Pasto";
}

void Pasto::interactuar(Carro *unCarro, int numeroDeSuelo) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
  unCarro -> actualizarPosicion(numeroDeSuelo);
}

Pasto::~Pasto() {
}
