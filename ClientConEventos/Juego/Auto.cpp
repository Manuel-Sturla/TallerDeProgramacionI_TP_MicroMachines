//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "Auto.h"
#include "../Sdl/Renderizador.h"

Auto::Auto(Renderizador &renderizador, int tam, std::string id) : Desplazable(renderizador, tam, id) {
    renderizador.agregarAuto("../Sprites/auto.png", &posicion, id);
    etapaExplosion = 0;
    idExplosion = "explosion";
}

void Auto::mover(float posX, float posY, int angulo) {
    if(etapaExplosion == 0){
        posicion.moverA(posX, posY);
        posicion.rotar(angulo);
    } else {
        morir();
    }
}

void Auto::morir() {
    if(etapaExplosion == 0){
        renderizador.agregarAuto("../Sprites/explosion0.png", &posicion, idExplosion);
        etapaExplosion++;
    } else if(etapaExplosion == 1) {
        renderizador.borrarAuto(idExplosion);
        renderizador.agregarAuto("../Sprites/explosion1.png", &posicion, idExplosion);
        etapaExplosion++;
    } else if(etapaExplosion == 2) {
        renderizador.borrarAuto(idExplosion);
        renderizador.agregarAuto("../Sprites/explosion2.png", &posicion, idExplosion);
        etapaExplosion++;
    } else {
        renderizador.borrarAuto(idExplosion);
        etapaExplosion = 0;
    }
}

void Auto::modificar(std::string &mensaje) {
}

void Auto::eliminar() {
    renderizador.borrarAuto(id);
}
