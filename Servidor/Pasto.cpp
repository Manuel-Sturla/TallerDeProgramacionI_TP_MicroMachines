#include "Pasto.h"

Pasto::Pasto() {
  id = "Pasto";
  coeficienteDeRozamiento = 0.6f;
}

std::string Pasto::darId() {
  return id;
}

void Pasto::interactuar() {
  printf("Sobre Pasto");
}

Pasto::~Pasto() {
}
