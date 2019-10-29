//
// Created by manfer on 28/10/19.
//

#include "ModBoost.h"
#include "../Carro.h"
void activar(void* carro){
    Carro* autito = static_cast<Carro*>(carro);
    float velMax = autito->obtenerVelicidadMax();
    autito->actualizarVelocidadMax(velMax*2);
}