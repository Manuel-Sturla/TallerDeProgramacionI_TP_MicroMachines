//
// Created by manfer on 7/11/19.
//

#ifndef SERVIDOR_ESTADOPARTIDA_H
#define SERVIDOR_ESTADOPARTIDA_H


#include <memory>

class EstadoPartida {
public:
    virtual void ejecutar() = 0;
    virtual bool enJuego() = 0;
    virtual void cerrar() = 0;
};


#endif //SERVIDOR_ESTADOPARTIDA_H
