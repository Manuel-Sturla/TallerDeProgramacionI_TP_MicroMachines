//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOACELERAR_H
#define OPENGLTEST_COMANDOACELERAR_H


#include "Comando.h"

class ComandoAcelerar : public Comando {
public:
    explicit ComandoAcelerar(Servidor &servidor) : Comando(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOACELERAR_H
