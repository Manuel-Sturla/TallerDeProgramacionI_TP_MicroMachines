//
// Created by diego on 23/10/19.
//

#ifndef OPENGLTEST_TEXTURA_H
#define OPENGLTEST_TEXTURA_H


#include <SDL2/SDL_system.h>
#include "Posicion.h"
#include "../Vista/Camara.h"
#include <string>

class Textura {
private:
    SDL_Texture* textura;
    Posicion* posicion;

public:
    Textura(SDL_Renderer* renderizador, const std::string& archivo, Posicion* pos);

    Textura(Textura&& text) noexcept;

    void copiar(SDL_Renderer* renderizador, Camara& camara);

    void moverA(int posX, int posY);

    void mover(Posicion& pos);

    virtual ~Textura();
};


#endif //OPENGLTEST_TEXTURA_H
