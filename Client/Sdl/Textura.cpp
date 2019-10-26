//
// Created by diego on 23/10/19.
//

#include "Textura.h"
#include "../Excepciones/ExcepcionConPos.h"
#include <SDL2/SDL_image.h>

Textura::Textura(SDL_Renderer *renderizador, const std::string &archivo, Posicion& pos, int angulo) : posicion(pos) {
    this->angulo = angulo;
    posicion = pos;
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude cargar la textura: " + archivo);
    }
    SDL_RenderCopyEx(renderizador, textura, nullptr, posicion.getRect(), angulo, nullptr, SDL_FLIP_VERTICAL);
}

void Textura::moverA(SDL_Renderer* renderizador, int posX, int posY) {
    posicion.moverA(posX, posY);
    SDL_RenderCopyEx(renderizador, textura, nullptr, posicion.getRect(), angulo, nullptr, SDL_FLIP_VERTICAL);
}

Textura::~Textura() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
}

void Textura::rotar(SDL_Renderer *renderizador, int angulo) {
    this->angulo = angulo;
    SDL_RenderCopyEx(renderizador, textura, nullptr, posicion.getRect(), angulo, nullptr, SDL_FLIP_VERTICAL);
}

void Textura::copiar(SDL_Renderer *renderizador) {
    SDL_RenderCopyEx(renderizador, textura, nullptr, posicion.getRect(), angulo, nullptr, SDL_FLIP_VERTICAL);
}
