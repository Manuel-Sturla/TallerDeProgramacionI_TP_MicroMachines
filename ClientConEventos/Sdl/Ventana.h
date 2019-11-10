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
public:
    Ventana(const char* titulo, int ancho, int largo);

    Ventana(const char* titulo, int ancho, int largo, int posX, int posY);

    virtual ~Ventana();

    SDL_Renderer *crearRenderizador(int indice, Uint32 flags);
};

#endif //OPENGLTEST_VENTANA_H
