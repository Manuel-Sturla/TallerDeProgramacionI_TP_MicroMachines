//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOFRENAR_H
#define OPENGLTEST_COMANDOFRENAR_H


#include <SDL2/SDL_stdinc.h>
#include "ComandoTeclado.h"

class ComandoFrenar : public ComandoTeclado {
public:
    explicit ComandoFrenar(ServidorProxy &servidor, const Uint8* estados) : ComandoTeclado(servidor, estados) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOFRENAR_H
