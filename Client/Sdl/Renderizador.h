//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_RENDERIZADOR_H
#define OPENGLTEST_RENDERIZADOR_H


#include "Ventana.h"
#include <SDL2/SDL.h>

class Renderizador {
private:
    SDL_Renderer* renderizador;
    Ventana ventana;

public:
    Renderizador();

    explicit Renderizador(Ventana& ventana);

    virtual ~Renderizador();
};


#endif //OPENGLTEST_RENDERIZADOR_H
