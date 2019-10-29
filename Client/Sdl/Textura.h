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
    Posicion* posicion;
    int angulo;

public:
    Textura(SDL_Renderer* renderizador, const std::string& archivo, Posicion* pos, int angulo);
    Textura(Textura&& otra);
    void copiar(SDL_Renderer* renderizador);

    void moverA(int posX, int posY);

    void mover(Posicion& pos);

    void rotar(int angulo);

    virtual ~Textura();
};


#endif //OPENGLTEST_TEXTURA_H
