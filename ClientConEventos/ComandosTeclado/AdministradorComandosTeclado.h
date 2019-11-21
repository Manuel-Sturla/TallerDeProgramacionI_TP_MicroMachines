//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_ADMINISTRADORCOMANDOS_H
#define OPENGLTEST_ADMINISTRADORCOMANDOS_H


#include <map>
#include <SDL2/SDL_keycode.h>
#include "ComandoTeclado.h"

class AdministradorComandosTeclado {
private:
    std::map<SDL_Keycode, ComandoTeclado*> comandos;
    const Uint8* estados;

public:
    explicit AdministradorComandosTeclado(ServidorProxy &servidor);

    virtual ~AdministradorComandosTeclado();

    void ejecutar();

    void apretar(SDL_Keycode comando);

    void desapretar(SDL_Keycode comando);
};


#endif //OPENGLTEST_ADMINISTRADORCOMANDOS_H
