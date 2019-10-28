#include "Vida.h"
#include <iostream>

Vida::Vida() {
  revivir();
}

void Vida::recibirDanio(int danio) {
  int nuevaVida = vida - danio;
  if (nuevaVida > 0) {
    vida = nuevaVida;
  } else {
    matar();
  }
}

void Vida::matar() {
  vida = 0;
  printf("Carro muerto\n");
}

void Vida::revivir() {
  vida = 100;
}

Vida::~Vida() {
}
