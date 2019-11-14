//
// Created by manfer on 14/11/19.
//

#include "Jugador.h"

int Jugador::obtenerComando() {
    return lector.leer();
}

bool Jugador::esCpu() {
    return cpu;
}
