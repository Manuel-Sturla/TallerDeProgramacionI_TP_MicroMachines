//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_COMANDOFRENAR_H
#define OPENGLTEST_COMANDOFRENAR_H


#include "Comando.h"

class ComandoFrenar : public Comando {
public:
    explicit ComandoFrenar(ServidorProxy &servidor) : Comando(servidor) {}

    void ejecutar() override;
};


#endif //OPENGLTEST_COMANDOFRENAR_H
