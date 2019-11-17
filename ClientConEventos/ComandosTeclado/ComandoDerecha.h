//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDODERECHA_H
#define OPENGLTEST_COMANDODERECHA_H


#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_events.h>
#include "ComandoTeclado.h"

class ComandoDerecha : public ComandoTeclado {
public:
    explicit ComandoDerecha(ServidorProxy &servidor, const Uint8* estados) : ComandoTeclado(servidor, estados) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDODERECHA_H
