//
// Created by diego on 2/11/19.
//

#ifndef OPENGLTEST_COMANDOINICIARPARTIDA_H
#define OPENGLTEST_COMANDOINICIARPARTIDA_H


#include "ComandoTeclado.h"

class ComandoIniciarPartida : public ComandoTeclado {
public:
    explicit ComandoIniciarPartida(ServidorProxy &servidor) : ComandoTeclado(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOINICIARPARTIDA_H
