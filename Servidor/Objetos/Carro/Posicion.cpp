#include "Posicion.h"

Posicion::Posicion() {
    numeroDeVueltas = 0;
    numeroDeSuelo = 0;
}

void Posicion::actualizar(int nuevoNumeroDeSuelo) {
    if (nuevoNumeroDeSuelo == 0 && numeroDeSuelo > 1) {
        numeroDeVueltas += 1;
    }
    numeroDeSuelo = nuevoNumeroDeSuelo;
}

bool Posicion::termineLaCarrera(int vueltasParaTerminar) {
    return numeroDeVueltas == vueltasParaTerminar;
}

Posicion::~Posicion() {
}

bool Posicion::operator<(const Posicion &otraposicion) {
    if (this->numeroDeVueltas < otraposicion.numeroDeVueltas) {
        return true;
    } else if (this->numeroDeVueltas > otraposicion.numeroDeVueltas) {
        return false;
    } else {
        return this->numeroDeSuelo <= otraposicion.numeroDeSuelo;
    }
}

int Posicion::obtenerSueloParaRevivir() {
    return numeroDeSuelo;
}
