//
// Created by diego on 29/10/19.
//

#ifndef OPENGLTEST_CAMARA_H
#define OPENGLTEST_CAMARA_H


#include "../Sdl/Posicion.h"

class Camara {
private:
    Posicion& posAuto;
    int tamPantalla;

public:
    Camara(Posicion& miAuto, int tamPantalla);

    SDL_Rect obtenerPosImpresion(Posicion* pos);
};


#endif //OPENGLTEST_CAMARA_H
