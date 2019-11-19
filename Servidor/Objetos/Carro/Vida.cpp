#include "Vida.h"
#define VIDA_MAX 100
#define ESPERA_PARA_REVIVIR 3

Vida::Vida() {
    enJuego = true;
    revivir();
    moriEnLaSimulacionActual = false;
}

void Vida::recibirDanio(int danio) {
  int nuevaVida = vida - danio;
  if (nuevaVida > 0) {
    vida = nuevaVida;
  } else {
    matar();
    esperaParaRevivir = ESPERA_PARA_REVIVIR;
      moriEnLaSimulacionActual = true;
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
        vida = VIDA_MAX;
        esperaParaRevivir = 0;
        moriEnLaSimulacionActual = false;
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
        moriEnLaSimulacionActual = false;
    }
    return (esperaParaRevivir == 0) && enJuego;
}

void Vida::salirDeJuego() {
    enJuego = false;
    matar();
}

bool Vida::moriRecientemente() {
    return moriEnLaSimulacionActual;
}

void Vida::empaquetar(std::vector<std::string> *destino) {
    destino -> emplace_back(vida);
}
