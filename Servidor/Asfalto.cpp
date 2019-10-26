#include "Asfalto.h"
#include "Interactuable.h"
#include <iostream>

Asfalto::Asfalto() {
  coeficienteDeRozamiento = 0.3f;
  id = "Asfalto";
}

std::string Asfalto::darId() {
  return id;
}

void Asfalto::interactuar() {
  printf("Sobre Asfalto\n");
}

Asfalto::~Asfalto() {
}
