//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDODERECHA_H
#define OPENGLTEST_COMANDODERECHA_H


#include "ComandoTeclado.h"

class ComandoDerecha : public ComandoTeclado {
public:
    explicit ComandoDerecha(ServidorProxy &servidor) : ComandoTeclado(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDODERECHA_H
