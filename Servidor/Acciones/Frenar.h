#ifndef _FRENAR_H_
#define _FRENAR_H_

#include "Accion.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

class Frenar: public Accion {
public:
    void ejecutar(b2Body& body, EstadoVelocidad &estadoVelocidad, float32 angulo);
};


#endif
