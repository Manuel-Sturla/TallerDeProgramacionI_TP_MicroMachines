//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_ADMINISTRADORCOMANDOS_H
#define OPENGLTEST_ADMINISTRADORCOMANDOS_H


#include <map>
#include <SDL2/SDL_keycode.h>
#include "ComandoTeclado.h"
#include "ComandoCerrar.h"

class AdministradorComandosTeclado {
private:
    std::vector<ComandoTeclado*> comandos;
    ComandoCerrar cerrar;
    const Uint8* estados;

public:
    explicit AdministradorComandosTeclado(ServidorProxy& servidor);

    virtual ~AdministradorComandosTeclado();

    void ejecutar();

    void cerrarPrograma();
};


#endif //OPENGLTEST_ADMINISTRADORCOMANDOS_H
