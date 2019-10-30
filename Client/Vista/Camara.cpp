//
// Created by diego on 29/10/19.
//

#include <iostream>
#include "Camara.h"

Camara::Camara(Posicion &posAuto, int tamPantalla) : posAuto(posAuto) {
    this->tamPantalla = tamPantalla;
}

SDL_Rect Camara::obtenerPosImpresion(SDL_Rect posPista) {
    SDL_Rect rectAuto = posAuto.getRect();
    posPista.x -=rectAuto.x - tamPantalla/2 + 50;
    posPista.y -= rectAuto.y - tamPantalla/2 + 50;
    return posPista;
}
