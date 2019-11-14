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
    std::map<SDL_Keycode, ComandoTeclado*> comandos;
    ComandoCerrar cerrar;
public:
    explicit AdministradorComandosTeclado(ServidorProxy& servidor);

    virtual ~AdministradorComandosTeclado();

    void ejecutar(SDL_Keycode &comando);

    void cerrarPrograma();
};


#endif //OPENGLTEST_ADMINISTRADORCOMANDOS_H
