//
// Created by diego on 23/10/19.
//

#include "Textura.h"
#include "../Excepciones/ExcepcionConPos.h"
#include <SDL2/SDL_image.h>

Textura::Textura(SDL_Renderer *renderizador, const std::string &archivo, SDL_Rect* pos) {
    posicion = pos;
    textura = IMG_LoadTexture(renderizador, archivo.c_str());
    if(textura == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude cargar la textura: " + archivo);
    }
    SDL_RenderCopy(renderizador, textura, nullptr, posicion);
}

void Textura::moverA(int posX, int posY) {
    posicion->x = posX;
    posicion->y = posY;
}

Textura::~Textura() {
    if(textura != nullptr){
        SDL_DestroyTexture(textura);
    }
}
