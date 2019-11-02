#include "Partida.h"

Partida::Partida(b2Vec2 gravedad): mapa(gravedad) {
}

void Partida::simular() {
  mapa.simular();
}

Partida::~Partida() {
}
