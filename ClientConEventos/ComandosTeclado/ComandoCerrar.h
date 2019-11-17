//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_COMANDOCERRAR_H
#define OPENGLTEST_COMANDOCERRAR_H


#include <SDL2/SDL_stdinc.h>
#include "ComandoTeclado.h"

class ComandoCerrar : public ComandoTeclado {
public:
    explicit ComandoCerrar(ServidorProxy &servidor, const Uint8* estados) : ComandoTeclado(servidor, estados) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOCERRAR_H
