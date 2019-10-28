#include "LimiteDePista.h"
#define VIDA_MAX_DE_CARRO 100

LimiteDePista::LimiteDePista() {
}

void LimiteDePista::interactuar(Carro *unCarro) {
  unCarro -> recibirDanio(VIDA_MAX_DE_CARRO);
}

std::string LimiteDePista::darId() {
  return "LimiteDePista";
}

LimiteDePista::~LimiteDePista() {
}
