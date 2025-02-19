#include <iostream>
#include "Posicion.h"

Posicion::Posicion() {
    numeroDeVueltas = 0;
    numeroDeSuelo = 0;
}

void Posicion::actualizar(int nuevoNumeroDeSuelo) {
    actualizarSuelosPorLosQuePase(nuevoNumeroDeSuelo);
    if (nuevoNumeroDeSuelo == 0 && suelosPorLosQuePase.top() > 5) {
        numeroDeVueltas += 1;
        suelosPorLosQuePase.empty();
        suelosPorLosQuePase.push(nuevoNumeroDeSuelo);
    }
    numeroDeSuelo = nuevoNumeroDeSuelo;
}

bool Posicion::termineLaCarrera(int vueltasParaTerminar) {
    return numeroDeVueltas == vueltasParaTerminar;
}

Posicion::~Posicion() {
}

bool Posicion::operator<=(const Posicion &otraposicion) {
    if (this->numeroDeVueltas < otraposicion.numeroDeVueltas) {
        return true;
    } else if (this->numeroDeVueltas > otraposicion.numeroDeVueltas) {
        return false;
    } else {
        return this->numeroDeSuelo < otraposicion.numeroDeSuelo;
    }
}

int Posicion::obtenerSueloParaRevivir() {
    return numeroDeSuelo;
}

void Posicion::actualizarSuelosPorLosQuePase(int nuevoNumeroDeSuelo) {
    if (suelosPorLosQuePase.empty() && nuevoNumeroDeSuelo == 0) {
        suelosPorLosQuePase.push(nuevoNumeroDeSuelo);
    } else if (!suelosPorLosQuePase.empty()) {
        if (suelosPorLosQuePase.top() == nuevoNumeroDeSuelo -1) {
            suelosPorLosQuePase.push(nuevoNumeroDeSuelo);
        } else if (suelosPorLosQuePase.top() - 1 == nuevoNumeroDeSuelo) {
            suelosPorLosQuePase.pop();
        }
    }
}
