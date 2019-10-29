//
// Created by diego on 23/10/19.
//

#include "Textura.h"
#include "../Excepciones/ExcepcionConPos.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Textura::Textura(SDL_Renderer *renderizador, const std::string &archivo, Posicion* pos, int angulo) : posicion(pos) {
    this->angulo = angulo;
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude cargar la textura: " + archivo);
    }
}

void Textura::moverA(int posX, int posY) {
    posicion->moverA(posX, posY);
}

void Textura::rotar(int angulo) {
    this->angulo = angulo;
}

void Textura::copiar(SDL_Renderer *renderizador) {
    if(SDL_RenderCopyEx(renderizador, textura, nullptr, posicion->getRect(), angulo, nullptr, SDL_FLIP_VERTICAL)<0){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

Textura::~Textura() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
}

void Textura::mover(Posicion &pos) {
    posicion->mover(pos);
}
