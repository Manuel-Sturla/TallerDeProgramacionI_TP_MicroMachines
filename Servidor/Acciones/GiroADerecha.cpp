#include <iostream>
#include "GiroADerecha.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

void GiroADerecha::ejecutar(b2Body &cuerpo, EstadoVelocidad &estadoVelocidad, float32 angulo) {
    //MATAR LA VELOCIDAD EN LA DIRECCION QUE NO SE ESTA GIRANDO O POR LO MENOS DISMINUIRLA
    float desiredAngularVelocity = - angulo * 60;
    float torque = cuerpo.GetInertia() * desiredAngularVelocity * 60.0;
    cuerpo.ApplyTorque(torque, true);
}
