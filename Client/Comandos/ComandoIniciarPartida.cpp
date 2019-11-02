//
// Created by diego on 2/11/19.
//

#include <iostream>
#include "ComandoIniciarPartida.h"

void ComandoIniciarPartida::ejecutar() {
    servidor.crearPartida("part1", 1);
}
