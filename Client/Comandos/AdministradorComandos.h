//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_ADMINISTRADORCOMANDOS_H
#define OPENGLTEST_ADMINISTRADORCOMANDOS_H


#include <map>
#include <SDL2/SDL_keycode.h>
#include "Comando.h"
#include "ComandoCerrar.h"

class AdministradorComandos {
private:
    std::map<SDL_Keycode, Comando*> comandos;
    ComandoCerrar cerrar;
public:
    explicit AdministradorComandos(ServidorProxy& servidor);

    virtual ~AdministradorComandos();

    void ejecutar(SDL_Keycode &comando);

    void cerrarPrograma();
};


#endif //OPENGLTEST_ADMINISTRADORCOMANDOS_H
