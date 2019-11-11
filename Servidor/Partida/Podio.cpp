#include <iostream>
#include "Podio.h"

Podio::~Podio() {
}

Podio::Podio(int cantidadDeVueltas) {
    this -> cantidadDeVueltas = cantidadDeVueltas;
}

bool comparar(Carro *primerCarro, Carro *segundoCarro) {
    return *segundoCarro < *primerCarro;
}

void Podio::actualizarPodio() {
    carros.sort(comparar);
}

void Podio::agregarCarro(Carro *carro) {
    carros.push_back(carro);
}

void Podio::analizarVictoria() {
    auto it = carros.begin();
    if ((*it) -> termineCarrera(cantidadDeVueltas)) {
        std::cout << "GANO EL WACHO" << std::endl;
    }
}
