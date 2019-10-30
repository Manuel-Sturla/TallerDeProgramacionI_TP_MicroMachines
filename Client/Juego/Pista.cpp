//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "Pista.h"

Pista::Pista(Renderizador &renderizador) {
    tamImagen = 1000;
    int posX = 0;
    int posY = 0;
    for(int i = 0; i < 4; ++i){
        auto* pos = new Posicion(posX, posY, 1000, tamImagen);
        posY -= tamImagen;
        renderizador.agregarTrecho("pista.png", pos, 90);
    }
}

void Pista::crearPista(Renderizador& renderizador) {
/*    int posX = 0;
    int posY = 0;
    for(int i = 0; i < 2; ++i){
        auto* pos = new Posicion(posX, posY, 1000, tamImagen);
        posY += tamImagen;
        renderizador.agregarTrecho("pista.png", pos, 90);
    }
}

void Pista::crearPista(Renderizador& renderizador) {
/*    int posX = 0;
    int posY = 0;
    for(int i = 0; i < 2; ++i){
        auto* pos = new Posicion(posX, posY, 1000, tamImagen);
        posY += tamImagen;
        renderizador.agregarTrecho("pista.png", pos, 90);
    }*/
}

