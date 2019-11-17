//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDO_H
#define OPENGLTEST_COMANDO_H


#include "../Sockets/ServidorProxy.h"

class ComandoTeclado {
protected:
    ServidorProxy& servidor;
    const Uint8* estados;

public:
    explicit ComandoTeclado(ServidorProxy &servidor, const Uint8 *estados) : servidor(servidor), estados(estados) {}

    virtual void ejecutar() = 0;

    virtual ~ComandoTeclado() = default;
};


#endif //OPENGLTEST_COMANDO_H
