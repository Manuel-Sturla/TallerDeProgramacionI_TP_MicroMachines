//
// Created by diego on 23/10/19.
//

#include "Textura.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../Vista/Camara.h"
#include <SDL2/SDL_image.h>
#include <iostream>

Textura::Textura(SDL_Renderer *renderizador, const std::string &archivo, Posicion* pos) : posicion(pos) {
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

Textura::Textura(Textura&& text) noexcept {
    this->textura = text.textura;
    this->posicion = text.posicion;
    text.textura = nullptr;
    text.posicion = nullptr;
}

void Textura::moverA(int posX, int posY) {
    posicion->moverA(posX, posY);
}

void Textura::copiar(SDL_Renderer *renderizador, Camara& camara) {
    SDL_Rect posImpresion = camara.obtenerPosImpresion(posicion);
    if(SDL_RenderCopyEx(renderizador, textura, nullptr, &posImpresion, posicion->getAngulo(), nullptr, SDL_FLIP_VERTICAL)<0){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

void Textura::mover(Posicion &pos) {
    posicion->mover(pos);
}

Textura::~Textura() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
}
