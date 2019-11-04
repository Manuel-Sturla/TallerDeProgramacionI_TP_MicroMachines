#include "Partida.h"

Partida::Partida() {
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

void Partida::simular() {
  mapa.simular();
}

void Partida::actualizar() {
    autos.clear();
    suelos.clear();
  mapa.empaquetarSuelos(&suelos);
  mapa.empaquetarCarro(&autos);
}

std::vector<std::string> &Partida::obtenerMapa() {
  return suelos;
}

Carro *Partida::getCarro() {
  return mapa.getCarro();
}
