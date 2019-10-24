//
// Created by diego on 23/10/19.
//

#ifndef OPENGLTEST_TEXTURA_H
#define OPENGLTEST_TEXTURA_H


#include <SDL2/SDL_render.h>
#include <string>
#include "Posicion.h"

class Textura {
private:
    SDL_Texture* textura;
    Posicion posicion;

public:
    Textura(SDL_Renderer* renderizador, const std::string& archivo, Posicion& pos);

    Textura(SDL_Renderer* renderizador, const std::string& archivo);

    void copiar(SDL_Renderer* renderizador);

    void moverA(SDL_Renderer* renderizador, int posX, int posY);

    virtual ~Textura();

    void rotar(SDL_Renderer *renderizador, int angulo);
};


#endif //OPENGLTEST_TEXTURA_H
