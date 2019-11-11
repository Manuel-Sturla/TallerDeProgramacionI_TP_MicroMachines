#include "Podio.h"

Podio::~Podio() {
}

Podio::Podio(int cantidadDeVueltas) {
    this -> cantidadDeVueltas = cantidadDeVueltas;
}

void Podio::actualizarPodio() {
    carros.sort();
}

void Podio::agregarCarro(Carro *carro) {
    carros.push_back(carro);
}
