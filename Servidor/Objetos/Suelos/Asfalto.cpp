#include "Asfalto.h"

Asfalto::Asfalto() {
  coeficienteDeRozamiento = 0.1f;
  id = "Asfalto";
}

void Asfalto::interactuar(Carro *unCarro, int numeroDeSuelo) {
  unCarro -> aplicarFriccion(coeficienteDeRozamiento);
  unCarro -> actualizarPosicion(numeroDeSuelo);
}

Asfalto::~Asfalto() {
}
