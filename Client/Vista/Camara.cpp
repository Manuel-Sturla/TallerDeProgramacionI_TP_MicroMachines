//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "Camara.h"

Camara::Camara(Renderizador& renderizador) : pista(renderizador, renderizador.getPista()), miAuto(renderizador) {
}

void Camara::inicializar() {
    pista.crearPista();
}

void Camara::actualizar(std::vector<int>& mensaje) {
    Posicion posFinal(mensaje[0], mensaje[1], 1000, 1000);
    pista.mover(posFinal - posCamara);
    posCamara = posFinal;
}
