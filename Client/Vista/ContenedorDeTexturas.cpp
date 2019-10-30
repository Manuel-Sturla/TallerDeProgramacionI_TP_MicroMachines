//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "ContenedorDeTexturas.h"

ContenedorDeTexturas::ContenedorDeTexturas(Renderizador& renderizador) : pista(renderizador), miAuto(renderizador, 100) {
}

void ContenedorDeTexturas::actualizar(std::vector<int>& mensaje) {
    miAuto.mover(mensaje[0], mensaje[1], mensaje[2]);
}

Auto& ContenedorDeTexturas::getAuto() {
    return miAuto;
}
