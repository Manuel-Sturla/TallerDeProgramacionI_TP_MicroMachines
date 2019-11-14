//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_COMANDOCERRAR_H
#define OPENGLTEST_COMANDOCERRAR_H


#include "ComandoTeclado.h"

class ComandoCerrar : public ComandoTeclado {
public:
    explicit ComandoCerrar(ServidorProxy &servidor) : ComandoTeclado(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOCERRAR_H
