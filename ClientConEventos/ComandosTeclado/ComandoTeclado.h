//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDO_H
#define OPENGLTEST_COMANDO_H


#include "../Sockets/ServidorProxy.h"

class ComandoTeclado {
protected:
    ServidorProxy& servidor;
public:
    explicit ComandoTeclado(ServidorProxy &servidor) : servidor(servidor) {}

    virtual void ejecutar() = 0;

    virtual ~ComandoTeclado() = default;
};


#endif //OPENGLTEST_COMANDO_H
