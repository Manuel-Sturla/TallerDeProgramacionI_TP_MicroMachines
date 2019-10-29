//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_CAMARA_H
#define OPENGLTEST_CAMARA_H


#include "../Sdl/Posicion.h"
#include "../Juego/Pista.h"
#include "../Juego/Auto.h"
#include "../Sdl/Renderizador.h"

class Camara {
private:
    Posicion posCamara;
    Pista pista;
    Auto miAuto;

public:
    explicit Camara(std::vector<Textura>& pista);

    void actualizar(std::vector<int>& mensaje);
};


#endif //OPENGLTEST_CAMARA_H
