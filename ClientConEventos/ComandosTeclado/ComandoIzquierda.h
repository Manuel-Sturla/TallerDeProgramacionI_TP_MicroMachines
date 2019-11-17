//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOIZQUIERDA_H
#define OPENGLTEST_COMANDOIZQUIERDA_H


#include <SDL2/SDL_stdinc.h>
#include "ComandoTeclado.h"

class ComandoIzquierda : public ComandoTeclado {
public:
    explicit ComandoIzquierda(ServidorProxy &servidor, const Uint8* estados) : ComandoTeclado(servidor, estados) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOIZQUIERDA_H
