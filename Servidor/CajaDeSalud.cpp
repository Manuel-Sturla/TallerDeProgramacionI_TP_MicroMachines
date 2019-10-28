#include "CajaDeSalud.h"
#define CURACION 5

void CajaDeSalud::interactuar(Carro *unCarro) {
  unCarro -> curar(CURACION);
}

std::string CajaDeSalud::darId() {
  return "CajaDeSalud";
}
