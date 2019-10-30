//
// Created by diego on 23/10/19.
//

#include "Textura.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../Vista/Camara.h"
#include <SDL2/SDL_image.h>

Textura::Textura(SDL_Renderer *renderizador, const std::string &archivo, Posicion* pos) : posicion(pos) {
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

Textura::Textura(Textura&& text) noexcept : posicion(text.posicion) {
    this->textura = text.textura;
    text.posicion = nullptr;
    text.textura = nullptr;
}

void Textura::copiar(SDL_Renderer *renderizador, Camara& camara) {
    if(posicion == nullptr){
        if(SDL_RenderCopyEx(renderizador, textura, nullptr, nullptr, 0, nullptr, SDL_FLIP_VERTICAL)<0){
            throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
        }
        return;
    }
    SDL_Rect posImpresion = camara.obtenerPosImpresion(posicion->getRect());
    if(SDL_RenderCopyEx(renderizador, textura, nullptr, &posImpresion, posicion->getAngulo(), nullptr, SDL_FLIP_VERTICAL)<0){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

void Textura::destruir() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
    textura = nullptr;
}

Textura::~Textura() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
}

Textura::Textura(SDL_Renderer* renderizador, const std::string& archivo) {
    posicion = nullptr;
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

Textura &Textura::operator=(const Textura &text) {
    this->posicion = text.posicion;
    this->textura = text.textura;
}
