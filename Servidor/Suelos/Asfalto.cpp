#include "Asfalto.h"

Asfalto::Asfalto() {
  coeficienteDeRozamiento = 0.3f;
  id = "Asfalto";
}

void Asfalto::interactuar(Carro* unCarro) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
}

Asfalto::~Asfalto() {
}
