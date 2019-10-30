#include "Recta.h"

Recta::Recta(Pista *pista, Material *unMaterial): cuadrado(pista, this) {
  material = unMaterial;
}

Recta::~Recta() {
}

void Recta::interactuar(Carro *unCarro) {
  material -> interactuar(unCarro);
}
