//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_LECTORTECLADO_H
#define OPENGLTEST_LECTORTECLADO_H


#include <SDL2/SDL_keycode.h>

class LectorTeclado {
private:
    bool activo;
public:
    LectorTeclado();

    static SDL_Keycode leer();
};


#endif //OPENGLTEST_LECTORTECLADO_H
