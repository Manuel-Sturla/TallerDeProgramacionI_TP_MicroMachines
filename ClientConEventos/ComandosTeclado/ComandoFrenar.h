//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOFRENAR_H
#define OPENGLTEST_COMANDOFRENAR_H


#include "ComandoTeclado.h"

class ComandoFrenar : public ComandoTeclado {
public:
    explicit ComandoFrenar(ServidorProxy &servidor) : ComandoTeclado(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOFRENAR_H
