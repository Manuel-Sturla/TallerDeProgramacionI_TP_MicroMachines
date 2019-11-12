#include <iostream>
#include "Vida.h"

Vida::Vida() {
    enJuego = true;
    revivir();
}

void Vida::recibirDanio(int danio) {
  int nuevaVida = vida - danio;
  if (nuevaVida > 0) {
    vida = nuevaVida;
  } else {
    matar();
    esperaParaRevivir = 3;
  }
}

void Vida::aumentarVida(int aumento) {
  vida += aumento;
}

void Vida::matar() {
  vida = 0;
}

void Vida::revivir() {
    if (enJuego) {
        std::cout << "Revivi" << std::endl;
        vida = 100;
        esperaParaRevivir = 0;
    } else {
        std::cout << "Yo no revivi" << std::endl;
    }

}

Vida::~Vida() {
}

bool Vida::estoyVivo() {
  return vida != 0;
}

bool Vida::puedoRevivir() {
    if (!estoyVivo()) {
        esperaParaRevivir -= 1;
    }
    return (esperaParaRevivir == 0) && enJuego;
}

void Vida::salirDeJuego() {
    enJuego = false;
    matar();
}
