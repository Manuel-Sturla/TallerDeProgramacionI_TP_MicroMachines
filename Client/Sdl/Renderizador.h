//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_RENDERIZADOR_H
#define OPENGLTEST_RENDERIZADOR_H


#include "Ventana.h"
#include "VectorDeTexturas.h"
#include <SDL2/SDL.h>

class Renderizador {
private:
    SDL_Renderer* renderizador;
    Ventana ventana;
    VectorDeTexturas texturas;

public:
    Renderizador();

    explicit Renderizador(Ventana& ventana);

    void agregarFondo(const std::string& archivo);

    void agregarTextura(const std::string& archivo, SDL_Rect* pos);

    void imprimir();

    virtual ~Renderizador();
};


#endif //OPENGLTEST_RENDERIZADOR_H
