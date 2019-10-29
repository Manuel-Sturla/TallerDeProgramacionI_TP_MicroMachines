//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_POSICION_H
#define OPENGLTEST_POSICION_H
#define PANTALLA_COMPLETA -1

#include <SDL2/SDL_rect.h>

class Posicion {
private:
    SDL_Rect posicion;
    bool pantallaCompleta;

public:
    Posicion();

    Posicion(int posX, int posY, int ancho, int altura);

    const SDL_Rect *getRect();

    void moverA(int posX, int posY);

    void mover(Posicion& pos);

    Posicion operator - (Posicion const& pos2);
};


#endif //OPENGLTEST_POSICION_H
