#include "Asfalto.h"
#include "../Interactuable.h"
#include <iostream>

Asfalto::Asfalto() {
  coeficienteDeRozamiento = 0.3f;
}

void Asfalto::interactuar(Carro* unCarro) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
}

Asfalto::~Asfalto() {
}
