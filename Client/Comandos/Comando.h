//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDO_H
#define OPENGLTEST_COMANDO_H


#include "../Sockets/ServidorProxy.h"

class Comando {
protected:
    ServidorProxy& servidor;
public:
    explicit Comando(ServidorProxy &servidor) : servidor(servidor) {}

    virtual void ejecutar() = 0;

    virtual ~Comando() = default;
};


#endif //OPENGLTEST_COMANDO_H
