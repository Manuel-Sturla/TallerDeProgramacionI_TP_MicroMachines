//
// Created by diego on 9/11/19.
//

#ifndef CLIENT_DESPLAZABLE_H
#define CLIENT_DESPLAZABLE_H


#include "../Sdl/Posicion.h"
#include "../Sdl/Renderizador.h"

class Desplazable {
protected:
    Posicion posicion;
    Renderizador& renderizador;
    std::string id;

public:
    Desplazable(Renderizador& renderizador, int tam, std::string id);

    virtual void mover(float posX, float posY, int angulo) = 0;

    virtual void morir() = 0;

    virtual void modificar(std::string& mensaje) = 0;

    Posicion* getPosicion();

    virtual void eliminar() = 0;

    virtual ~Desplazable() = default;
};


#endif //CLIENT_DESPLAZABLE_H
