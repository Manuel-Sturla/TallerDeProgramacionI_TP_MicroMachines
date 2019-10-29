//
// Created by diego on 24/10/19.
//

#include <iostream>
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

Posicion Posicion::operator-(Posicion const &pos) {
    return {posicion.x-pos.posicion.x, posicion.y-pos.posicion.y, posicion.w, posicion.h};
}

void Posicion::mover(Posicion& pos) {
    posicion.x += pos.posicion.x;
    posicion.y += pos.posicion.y;
    std::cout<<posicion.x<<','<<posicion.y<<'\n';
}
