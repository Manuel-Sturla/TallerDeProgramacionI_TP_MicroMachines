//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_PARTIDA_H
#define OPENGLTEST_PARTIDA_H


#include "../Vista/HiloVisualizacion.h"
#include "../Lector/HiloLector.h"

class Partida {
private:
    Hilo* vista;
    Hilo* lector;

public:
    explicit Partida(Servidor& servidor);

    void iniciar();

    virtual ~Partida();

};


#endif //OPENGLTEST_PARTIDA_H
