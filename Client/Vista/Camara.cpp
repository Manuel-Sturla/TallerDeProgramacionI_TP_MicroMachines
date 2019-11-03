//
// Created by diego on 29/10/19.
//

#include <iostream>
#include "Camara.h"
#include "../Excepciones/ExcepcionConPos.h"

Camara::Camara(int tamPantalla, int aumento) {
    this->aumento = aumento;
    this->posAuto = nullptr;
    this->tamPantalla = tamPantalla;
}

SDL_Rect Camara::obtenerPosImpresion(SDL_Rect posPista) {
    if(posAuto == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "La partida no fue inicializada");
    }
    SDL_Rect rectAuto = posAuto->getRect();
    amplificarValores(rectAuto);
    amplificarValores(posPista);
    if(esAuto(rectAuto, posPista)){
        posPista.x -= rectAuto.w/2;
        posPista.y -= rectAuto.h/2;
    }
    posPista.x -= rectAuto.x - tamPantalla/2;
    posPista.y -= rectAuto.y - tamPantalla/2;
    return posPista;
}

void Camara::setPosAuto(Posicion *pos) {
    posAuto = pos;
}

void Camara::amplificarValores(SDL_Rect &rect) {
    rect.x -= rect.w/2;
    rect.y -= rect.h/2;
    rect.x = rect.x * aumento;
    rect.y = rect.y * aumento;
    rect.w = rect.w * aumento;
    rect.h = rect.h * aumento;
}

bool Camara::esAuto(SDL_Rect &rectAuto, SDL_Rect &posPista) {
    return ((rectAuto.x == posPista.x) && (rectAuto.y == posPista.y)\
    && (rectAuto.w == posPista.w) && (rectAuto.h == posPista.h));
}
