#include "Modificador.h"

std::string Modificador::darId() {
  return tipo;
}

void Modificador::empaquetar(std::vector<std::string> *destino) {
    destino -> emplace_back(id);
    destino -> emplace_back(tipo);
    empaquetarPosicion(destino);
}
