#include "Partida.h"

Partida::Partida(b2Vec2 gravedad): mapa(gravedad) {
}

void Partida::simular() {
  mapa.simular();
}

Partida::~Partida() {
}

void Partida::crearPista(PlanoDePista *planoDePista) {
  planoDePista -> crearPista(&mapa, mapa.darPista());
}
