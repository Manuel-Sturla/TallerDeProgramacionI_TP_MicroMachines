//
// Created by diego on 29/10/19.
//

#include <iostream>
#include "Camara.h"

Camara::Camara(Posicion &posAuto, int tamPantalla) : posAuto(posAuto) {
    this->tamPantalla = tamPantalla;
}

SDL_Rect Camara::obtenerPosImpresion(Posicion* pos) {
    SDL_Rect rectAuto = posAuto.getRect();
    SDL_Rect posImpresion = pos->getRect();
    posImpresion.x -= rectAuto.x - tamPantalla/2;
    posImpresion.y -= rectAuto.y - tamPantalla/2;
    return posImpresion;
}
