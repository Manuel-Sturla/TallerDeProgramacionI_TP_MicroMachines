//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_AUTO_H
#define OPENGLTEST_AUTO_H


#include "../Sdl/Posicion.h"
#include "../Sdl/Renderizador.h"

class Auto {
private:
    Posicion posicion;

public:
    Auto(Renderizador &renderizador, int tam);

    void mover(float posX, float posY, int &angulo);

    Posicion& getPos();
};


#endif //OPENGLTEST_AUTO_H
