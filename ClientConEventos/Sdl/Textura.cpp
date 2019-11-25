//
// Created by diego on 23/10/19.
//

#include "Textura.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../Vista/Camara.h"
#include <SDL2/SDL_image.h>

Textura::Textura(SDL_Renderer *renderizador, const std::string &archivo, Posicion* pos) : posicion(pos) {
    superficie = nullptr;
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

Textura::Textura(SDL_Texture *textura, Posicion *pos, SDL_Surface *superificie) : textura(textura), posicion(pos), superficie(superificie) {}

Textura::Textura(Textura&& text) noexcept : posicion(text.posicion) {
    this->textura = text.textura;
    this->superficie = text.superficie;
    text.posicion = nullptr;
    text.textura = nullptr;
    text.superficie = nullptr;
}

bool Textura::copiar(SDL_Renderer *renderizador, Camara& camara) {
    if(posicion == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "Posicion invalida");
    }
    if(!camara.estaEnRango(posicion->getPosicion())){
        return true;
    }
    SDL_Rect posImpresion = camara.obtenerPosImpresion(posicion->getPosicion());
    if(SDL_RenderCopyEx(renderizador, textura, nullptr, &posImpresion,\
    camara.obtenerAngulo(posicion->getAngulo()), nullptr, SDL_FLIP_NONE)<0){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
    return true;
}

void Textura::copiar(SDL_Renderer* renderizador){
    pos_t aux = posicion->getPosicion();
    SDL_Rect posImpresion;
    posImpresion.x = aux.x;
    posImpresion.y = aux.y;
    posImpresion.w = aux.w;
    posImpresion.h = aux.h;
    if(SDL_RenderCopyEx(renderizador, textura, nullptr, &posImpresion,\
    posicion->getAngulo(), nullptr, SDL_FLIP_NONE)<0){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
}

void Textura::destruir() {
    if(superficie != nullptr){
        SDL_FreeSurface(superficie);
    }
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
    textura = nullptr;
}

Textura &Textura::operator=(const Textura &text) {
    this->posicion = text.posicion;
    this->textura = text.textura;
    return *this;
}

Textura::~Textura() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
}
