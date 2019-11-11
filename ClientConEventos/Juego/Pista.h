//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_PISTA_H
#define OPENGLTEST_PISTA_H


#include <vector>
#include "../Sdl/Renderizador.h"

class Pista {
    Renderizador& renderizador;
    int tamImagen;
    std::vector<Posicion*> pistaPos;

    void agregarPasto(int posX, int posY, int angulo);

    void agregarRecta(int posX, int posY, int angulo);

    void agregarCurva(int posX, int posY, int angulo);

public:

    explicit Pista(Renderizador &renderizador);

    void crear(std::vector<std::string>& instrucciones);

    virtual ~Pista();
};


#endif //OPENGLTEST_PISTA_H
