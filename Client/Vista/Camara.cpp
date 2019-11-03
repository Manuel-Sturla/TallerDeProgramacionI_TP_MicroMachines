//
// Created by diego on 29/10/19.
//

#include <iostream>
#include "Camara.h"
#include "../Excepciones/ExcepcionConPos.h"

Camara::Camara(int tamPantalla) {
    this->posAuto = nullptr;
    this->tamPantalla = tamPantalla;
}

SDL_Rect Camara::obtenerPosImpresion(SDL_Rect posPista) {
    if(posAuto == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "La partida no fue inicializada");
    }
    SDL_Rect rectAuto = posAuto->getRect();
    posPista.x -=rectAuto.x - tamPantalla/2 + 50;
    posPista.y -= rectAuto.y - tamPantalla/2 + 50;
    return posPista;
}

void Camara::setPosAuto(Posicion *pos) {
    posAuto = pos;
}
