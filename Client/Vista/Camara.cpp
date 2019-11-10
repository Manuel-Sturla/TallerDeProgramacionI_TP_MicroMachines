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
    amplificarValores(aux);
    amplificarValores(posTextura);
    posTextura.x -= aux.x;
    posTextura.y -= aux.y;
    posTextura.x -= posTextura.w/2;
    posTextura.y -= posTextura.h/2;
    SDL_Rect posImpresion;
    posImpresion.x = (int)posTextura.x;
    posImpresion.y = (int)posTextura.y;
    posImpresion.h = (int)posTextura.w;
    posImpresion.w = (int)posTextura.h;
    posImpresion.x += tamPantalla / 2;
    posImpresion.y += tamPantalla / 2;
    return posImpresion;
}

void Camara::setAuto(Posicion *pos) {
    posAuto = pos;
}

void Camara::amplificarValores(pos_t &pos) {
    pos.x *= aumento;
    pos.y *= aumento;
    pos.w *= aumento;
    pos.h *= aumento;
}

int Camara::obtenerAngulo(int angulo) {
    return (-1*angulo-90);
}

bool Camara::estaEnRango(pos_t posTextura) {
    pos_t aux = posAuto->getPosicion();
    if(abs(posTextura.x-aux.x) > (tamPantalla/aumento + posTextura.w)/2){
        return false;
    } else if(abs(posTextura.y-aux.y) > (tamPantalla/aumento + posTextura.h)/2) {
        return false;
    }
    return true;
}
