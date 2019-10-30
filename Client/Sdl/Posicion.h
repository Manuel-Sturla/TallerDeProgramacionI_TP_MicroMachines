//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_POSICION_H
#define OPENGLTEST_POSICION_H

#include <SDL2/SDL_rect.h>

class Posicion {
private:
    SDL_Rect posicion;
    int angulo;

public:
    Posicion(int posX, int posY, int ancho, int altura, int angulo);

    SDL_Rect getRect();

    void moverA(int posX, int posY);

    void mover(Posicion& pos);

    void rotar(int angulo);

    int getAngulo();

    Posicion operator - (Posicion const& pos2);

    bool estaEnRango(int ancho, int largo);
};


#endif //OPENGLTEST_POSICION_H
