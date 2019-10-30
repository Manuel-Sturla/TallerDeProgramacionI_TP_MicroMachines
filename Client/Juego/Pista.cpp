//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "Pista.h"

Pista::Pista(Renderizador &renderizador) {
    tamImagen = 1000;
    int posX = 0;
    int posY = 0;
    for(int i = 0; i < 2; ++i){
        auto* pos = new Posicion(posX, posY, 1000, tamImagen, 90);
        posY += tamImagen;
        renderizador.agregarTrecho("pista.png", pos);
    }
}

