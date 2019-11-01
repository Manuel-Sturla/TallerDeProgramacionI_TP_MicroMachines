//
// Created by diego on 28/10/19.
//

#ifndef OPENGLTEST_CONTENEDORDETEXTURAS_H
#define OPENGLTEST_CONTENEDORDETEXTURAS_H


#include "../Sdl/Posicion.h"
#include "../Juego/Pista.h"
#include "../Juego/Auto.h"
#include "../Sdl/Renderizador.h"
#include "../Servidor.h"

class ContenedorDeTexturas {
private:
    Servidor& servidor;
    Pista pista;
    Auto miAuto;

public:
    ContenedorDeTexturas(Renderizador& renderizador, Servidor& servidor);

    bool actualizar();

    Auto& getAuto();
};


#endif //OPENGLTEST_CONTENEDORDETEXTURAS_H
