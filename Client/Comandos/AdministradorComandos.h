//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_ADMINISTRADORCOMANDOS_H
#define OPENGLTEST_ADMINISTRADORCOMANDOS_H


#include <map>
#include <SDL2/SDL_keycode.h>
#include "Comando.h"

class AdministradorComandos {
private:
    std::map<SDL_Keycode, Comando*> comandos;
public:
    explicit AdministradorComandos(ServidorProxy& servidor);

    virtual ~AdministradorComandos();

    void ejecutar(SDL_Keycode &comando);
};


#endif //OPENGLTEST_ADMINISTRADORCOMANDOS_H
