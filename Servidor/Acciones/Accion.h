#ifndef _ACCION_H_
#define _ACCION_H_

#include "Box2D/Box2D.h"
#include "../Objetos/Carro/Velocidad.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

class Accion {
public:
    virtual void ejecutar(b2Body& body, EstadoVelocidad &estadoVelocidad, float32 angulo) = 0;
};


#endif
