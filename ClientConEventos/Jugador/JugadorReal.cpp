//
// Created by manfer on 14/11/19.
//

#include "JugadorReal.h"

int JugadorReal::obtenerComando() {
    return lector.leer();
}

JugadorReal::JugadorReal(): Jugador(false) {
}
