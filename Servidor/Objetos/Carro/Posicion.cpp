#include <iostream>
#include "Posicion.h"

Posicion::Posicion() {
    numeroDeVueltas = 0;
    numeroDeSuelo = 0;
}

void Posicion::actualizar(int nuevoNumeroDeSuelo) {
    if (nuevoNumeroDeSuelo == 0 && numeroDeSuelo > 1) {
        numeroDeVueltas += 1;
        std::cout << "Mi suelo actual es: " << numeroDeSuelo << std::endl;
        std::cout << "Mi nuevo suelo es: " << nuevoNumeroDeSuelo << std::endl;
        std::cout << "Una sola vueltaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
    }
    numeroDeSuelo = nuevoNumeroDeSuelo;
}

bool Posicion::termineLaCarrera(int vueltasParaTerminar) {
    return numeroDeVueltas == vueltasParaTerminar;
}

Posicion::~Posicion() {
}
