#ifndef _GIROADERECHA_H_
#define _GIROADERECHA_H_

#include "Accion.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

class GiroADerecha: public Accion {
public:
    void ejecutar(b2Body& body, EstadoVelocidad &estadoVelocidad, float32 angulo);
};


#endif
