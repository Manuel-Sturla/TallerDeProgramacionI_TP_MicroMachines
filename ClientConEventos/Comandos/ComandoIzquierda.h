//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOIZQUIERDA_H
#define OPENGLTEST_COMANDOIZQUIERDA_H


#include "Comando.h"

class ComandoIzquierda : public Comando {
public:
    explicit ComandoIzquierda(ServidorProxy &servidor) : Comando(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOIZQUIERDA_H
