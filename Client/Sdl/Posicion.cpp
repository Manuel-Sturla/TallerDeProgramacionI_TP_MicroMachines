//
// Created by diego on 24/10/19.
//

#include "Posicion.h"

Posicion::Posicion(int posX, int posY, int ancho, int altura) {
    pantallaCompleta = false;
    posicion.x = posX;
    posicion.y = posY;
    posicion.w = ancho;
    posicion.h = altura;
}

const SDL_Rect *Posicion::getRect() {
    if(pantallaCompleta){
        return nullptr;
    }
    return &posicion;
}

Posicion::Posicion() {
    pantallaCompleta = true;
}

void Posicion::moverA(int posX, int posY) {
    posicion.x = posX;
    posicion.y = posY;
}
