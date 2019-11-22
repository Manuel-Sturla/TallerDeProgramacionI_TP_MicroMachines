//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_VENTANA_H
#define OPENGLTEST_VENTANA_H


#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

class Ventana {
private:
    SDL_Window* ventana;
    int altura;
    int ancho;

public:
    Ventana(const char* titulo, int ancho, int altura);

    SDL_Renderer *crearRenderizador(int indice, Uint32 flags);

    virtual ~Ventana();

    int obtenerAltura();

    int obtenerAncho();
};

#endif //OPENGLTEST_VENTANA_H
