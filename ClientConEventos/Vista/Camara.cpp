//
// Created by diego on 29/10/19.
//

#include "Camara.h"
#include "../Excepciones/ExcepcionConPos.h"

Camara::Camara(int anchoPantalla, int alturaPantalla, int aumento) {
    this->aumento = aumento;
    this->posAuto = nullptr;
    this->anchoPantalla = anchoPantalla;
    this->alturaPantalla = alturaPantalla;
}

SDL_Rect Camara::obtenerPosImpresion(pos_t posTextura) {
    if(posAuto == nullptr){
        SDL_Rect posImpresion;
        posImpresion.x = (int)posTextura.x;
        posImpresion.y = (int)posTextura.y;
        posImpresion.h = (int)posTextura.w;
        posImpresion.w = (int)posTextura.h;
        return posImpresion;
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
    posImpresion.x += anchoPantalla / 2;
    posImpresion.y += alturaPantalla / 2;
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
    if(!posAuto){
        return true;
    }
    pos_t aux = posAuto->getPosicion();
    if(abs(posTextura.x-aux.x) > (anchoPantalla/aumento + posTextura.w)/2){
        return false;
    } else if(abs(posTextura.y-aux.y) > (alturaPantalla/aumento + posTextura.h)/2) {
        return false;
    }
    return true;
}
