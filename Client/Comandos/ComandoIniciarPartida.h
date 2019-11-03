//
// Created by diego on 2/11/19.
//

#ifndef OPENGLTEST_COMANDOINICIARPARTIDA_H
#define OPENGLTEST_COMANDOINICIARPARTIDA_H


#include "Comando.h"

class ComandoIniciarPartida : public Comando {
public:
    explicit ComandoIniciarPartida(ServidorProxy &servidor) : Comando(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOINICIARPARTIDA_H
