//
// Created by diego on 29/10/19.
//

#ifndef OPENGLTEST_CAMARA_H
#define OPENGLTEST_CAMARA_H


#include "../Sdl/Posicion.h"

class Camara {
private:
    Posicion* posAuto;
    int tamPantalla;

public:
    explicit Camara(int tamPantalla);

    void setPosAuto(Posicion* pos);

    SDL_Rect obtenerPosImpresion(SDL_Rect posPista);
};


#endif //OPENGLTEST_CAMARA_H
