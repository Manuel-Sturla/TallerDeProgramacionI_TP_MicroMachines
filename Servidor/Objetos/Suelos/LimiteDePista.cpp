#include "LimiteDePista.h"
#define VIDA_MAX_DE_CARRO 1000

LimiteDePista::LimiteDePista() {
  id = "Limite";
}

void LimiteDePista::interactuar(Carro *unCarro, int numeroDeSuelo) {
  unCarro -> recibirDanio(VIDA_MAX_DE_CARRO);
}

LimiteDePista::~LimiteDePista() {
}
