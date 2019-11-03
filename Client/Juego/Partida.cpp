//
// Created by diego on 24/10/19.
//

#include <iostream>
#include "Partida.h"

Partida::Partida(ServidorProxy &servidor) {
//    vista = new HiloVisualizacion(servidor);
}

void Partida::iniciar() {\
    vista->start();
}

Partida::~Partida() {
    vista->join();
    delete(vista);
}
