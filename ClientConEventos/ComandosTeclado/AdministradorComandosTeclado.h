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
    std::vector<ComandoTeclado*> comandos;
    const Uint8* estados;

public:
    explicit AdministradorComandosTeclado(ServidorProxy &servidor);

    virtual ~AdministradorComandosTeclado();

    void ejecutar();
};


#endif //OPENGLTEST_ADMINISTRADORCOMANDOS_H
