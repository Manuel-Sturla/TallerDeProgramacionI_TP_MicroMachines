//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_AUTO_H
#define OPENGLTEST_AUTO_H


#include "../Sdl/Renderizador.h"

class Auto {
private:
    Renderizador& renderizador;

public:
    explicit Auto(Renderizador& renderizador);
};


#endif //OPENGLTEST_AUTO_H
