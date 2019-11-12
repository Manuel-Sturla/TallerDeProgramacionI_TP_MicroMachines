//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "Auto.h"
#include "../Sdl/Renderizador.h"

Auto::Auto(Renderizador &renderizador, int tam) : Desplazable(renderizador, tam) {
    renderizador.agregarTextura("../Sprites/auto.png", &posicion);
    etapaExplosion = 0;
}

void Auto::mover(float posX, float posY, int angulo) {
    posicion.moverA(posX, posY);
    posicion.rotar(angulo);
}

void Auto::morir() {
    etapaExplosion++;
    if(etapaExplosion == 1){
        idExplosion = renderizador.agregarTextura("../Sprites/explosion0.png", &posicion);
        etapaExplosion++;
    } else if(etapaExplosion == 2) {
        renderizador.borrarTextura(idExplosion);
        idExplosion = renderizador.agregarTextura("../Sprites/explosion1.png", &posicion);
        etapaExplosion++;
    } else if(etapaExplosion == 3) {
        renderizador.borrarTextura(idExplosion);
        idExplosion = renderizador.agregarTextura("../Sprites/explosion2.png", &posicion);
        etapaExplosion++;
    } else {
        idExplosion = -1;
        etapaExplosion = 0;
    }
}

void Auto::modificar(std::string &mensaje) {
}
