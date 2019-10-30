//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_CONTENEDORDETEXTURAS_H
#define OPENGLTEST_CONTENEDORDETEXTURAS_H


#include "../Sdl/Posicion.h"
#include "../Juego/Pista.h"
#include "../Juego/Auto.h"
#include "../Sdl/Renderizador.h"

class ContenedorDeTexturas {
private:
    Pista pista;
    Auto miAuto;

public:
    explicit ContenedorDeTexturas(Renderizador& renderizador);

    void actualizar(std::vector<int>& mensaje);

    Auto& getAuto();
};


#endif //OPENGLTEST_CONTENEDORDETEXTURAS_H
