#include <iostream>
#include "Podio.h"

Podio::~Podio() {
}

Podio::Podio(int cantidadDeVueltas) {
    this -> cantidadDeVueltas = cantidadDeVueltas;
}

bool comparar(Carro *primerCarro, Carro *segundoCarro) {
    return *segundoCarro <= *primerCarro;
}

void Podio::actualizarPodio() {
    carros.sort(comparar);
}

void Podio::agregarCarro(Carro *carro) {
    carros.push_back(carro);
}

bool Podio::analizarVictoria() {
    auto it = carros.begin();
    return (*it) -> termineCarrera(cantidadDeVueltas);
}

std::string Podio::obtenerGanador() {
    auto it = carros.begin();
    std::string mensaje = "El ganador es: ";
    mensaje += (*it) -> darIdConductor();
    return mensaje;
}

void Podio::empaquetarPodio(std::vector<std::string> *destino) {
    for (auto it = carros.begin(); it != carros.end(); it++) {
        (*it) -> empaquetarId(destino);
    }
}
