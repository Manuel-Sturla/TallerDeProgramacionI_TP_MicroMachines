//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOACELERAR_H
#define OPENGLTEST_COMANDOACELERAR_H


#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_events.h>
#include "ComandoTeclado.h"

class ComandoAcelerar : public ComandoTeclado {
public:
    explicit ComandoAcelerar(ServidorProxy &servidor, const Uint8* estados) : ComandoTeclado(servidor, estados) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOACELERAR_H
