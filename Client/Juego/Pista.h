//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_PISTA_H
#define OPENGLTEST_PISTA_H


#include <vector>
#include "../Sdl/Textura.h"
#include "../Sdl/Renderizador.h"

class Pista {
    Renderizador& renderizador;
    std::vector<Textura>& pista;
    int tamImagen;

public:
    Pista(Renderizador& renderizador, std::vector<Textura>& pista);

    void crearPista();

    void mover(Posicion posicion);
};


#endif //OPENGLTEST_PISTA_H
