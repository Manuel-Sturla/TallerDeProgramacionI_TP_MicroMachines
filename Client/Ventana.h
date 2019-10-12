#ifndef OPENGLTEST_VENTANA_H
#define OPENGLTEST_VENTANA_H


#include <SDL2/SDL_render.h>

class Ventana {
private:
    SDL_Renderer* renderizador;
    SDL_Window* ventana;

public:
    Ventana(int ancho, int altura);

    virtual ~Ventana();

    SDL_Renderer *getRenderizador();
};


#endif //OPENGLTEST_VENTANA_H
