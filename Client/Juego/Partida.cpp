//
// Created by diego on 24/10/19.
//

#include <iostream>
#include "Partida.h"

Partida::Partida(Servidor &servidor) {
    lector = new HiloLector(servidor);
    vista = new HiloVisualizacion(servidor);
}

void Partida::iniciar() {
    lector->start();
    vista->start();
}

Partida::~Partida() {
    lector->join();
    vista->join();
    delete(vista);
    delete(lector);
}
