//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_PISTA_H
#define OPENGLTEST_PISTA_H


#include <vector>
#include "../Sdl/Renderizador.h"

class Pista {
    int tamImagen;
    std::vector<Posicion*> pistaPos;

public:
    explicit Pista(Renderizador &renderizador);

    virtual ~Pista();
};


#endif //OPENGLTEST_PISTA_H
