#include "Partida.h"

Partida::Partida() {
}

void Partida::simular() {
  mapa.simular();
}

Partida::~Partida() {
}

void Partida::crearPista(PlanoDePista *planoDePista) {
  planoDePista -> crearPista(&mapa, mapa.darPista());
}

std::vector<std::string> &Partida::obtenerExtras() {
  return extras;
}

std::vector<std::string> &Partida::obtenerAutos() {
  return autos;
}
