//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDODERECHA_H
#define OPENGLTEST_COMANDODERECHA_H


#include "Comando.h"

class ComandoDerecha : public Comando {
public:
    explicit ComandoDerecha(Servidor &servidor) : Comando(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDODERECHA_H
