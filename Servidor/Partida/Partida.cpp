#include "Partida.h"

Partida::Partida() {
}

Partida::~Partida() {
}

void Partida::crearPista(PlanoDePista *planoDePista) {
    planoDePista -> crearPista(&pista);
}

std::vector<std::string> &Partida::obtenerExtras() {
    return extras;
}

std::vector<std::string> &Partida::obtenerAutos() {
    return autos;
}

void Partida::simular() {
    pista.simular();
}

void Partida::actualizar() {
    autos.clear();
    suelos.clear();
    pista.empaquetarSuelos(&suelos);
    pista.empaquetarCarro(&autos);
}

std::vector<std::string> &Partida::obtenerMapa() {
    return suelos;
}

Carro *Partida::agregarCliente(PlanoDeCarro *planoDeCarro) {
    return planoDeCarro -> crearCarro(&pista);
}
