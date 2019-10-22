//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDO_H
#define OPENGLTEST_COMANDO_H


#include "../Servidor.h"

class Comando {
protected:
    Servidor& servidor;
public:
    explicit Comando(Servidor &servidor) : servidor(servidor) {}

    virtual void ejecutar() = 0;

    virtual ~Comando() = default;
};


#endif //OPENGLTEST_COMANDO_H
