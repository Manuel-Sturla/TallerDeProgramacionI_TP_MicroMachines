//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_COMANDOCERRAR_H
#define OPENGLTEST_COMANDOCERRAR_H


#include "Comando.h"

class ComandoCerrar : public Comando {
public:
    explicit ComandoCerrar(Servidor &servidor) : Comando(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOCERRAR_H
