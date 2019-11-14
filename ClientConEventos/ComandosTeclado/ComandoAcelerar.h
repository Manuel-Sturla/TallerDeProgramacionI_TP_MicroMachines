//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOACELERAR_H
#define OPENGLTEST_COMANDOACELERAR_H


#include "ComandoTeclado.h"

class ComandoAcelerar : public ComandoTeclado {
public:
    explicit ComandoAcelerar(ServidorProxy &servidor) : ComandoTeclado(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOACELERAR_H
