//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOIZQUIERDA_H
#define OPENGLTEST_COMANDOIZQUIERDA_H


#include "ComandoTeclado.h"

class ComandoIzquierda : public ComandoTeclado {
public:
    explicit ComandoIzquierda(ServidorProxy &servidor) : ComandoTeclado(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOIZQUIERDA_H
