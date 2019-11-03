#include "Modificador.h"

std::string Modificador::darId() {
  return id;
}

void Modificador::empaquetar(std::vector<std::string> *destino) {
  destino -> emplace_back(id);
  empaquetarPosicion(destino);
}

