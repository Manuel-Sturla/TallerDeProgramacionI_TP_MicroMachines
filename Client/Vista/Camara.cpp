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

SDL_Rect Camara::obtenerPosImpresion(pos_t posTextura) {
    if(posAuto == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "La partida no fue inicializada");
    }
    pos_t aux = posAuto->getPosicion();
    std::cout<<"Pos auto: "<<aux.x<<','<<aux.y<<'\n';
    amplificarValores(aux);
    amplificarValores(posTextura);
    posTextura.x -= posTextura.w/2;
    posTextura.y -= posTextura.h/2;
    SDL_Rect posImpresion;
    posImpresion.x = (int)posTextura.x;
    posImpresion.y = (int)posTextura.y;
    posImpresion.h = (int)posTextura.w;
    posImpresion.w = (int)posTextura.h;
    posImpresion.x += tamPantalla / 2;
    posImpresion.y += tamPantalla / 2;
//    std::cout<<posImpresion.x<<','<<posImpresion.y<<'\n';
    return posImpresion;
}

void Camara::setPosAuto(Posicion *pos) {
    posAuto = pos;
}

void Camara::amplificarValores(pos_t &pos) {
    pos.x *= aumento;
    pos.y *= aumento;
    pos.w *= aumento;
    pos.h *= aumento;
}

bool Camara::esAuto(pos_t &posAuto, pos_t &posText) {
    return posText.x == posAuto.x && posText.y == posAuto.y && posText.w == posAuto.w\
    && posText.h == posAuto.h;
}
