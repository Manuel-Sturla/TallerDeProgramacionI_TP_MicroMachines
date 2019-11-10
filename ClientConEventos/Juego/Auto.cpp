//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "Auto.h"
#include "../Sdl/Renderizador.h"

Auto::Auto(Renderizador &renderizador, int tam) : Desplazable(renderizador, tam) {
    renderizador.agregarTextura("auto.png", &posicion);
}

void Auto::mover(float posX, float posY, int angulo) {
    posicion.moverA(posX, posY);
    posicion.rotar(angulo);
}

void Auto::morir() {
    //Aca iria lo de la explosion
}

void Auto::modificar(std::string &mensaje) {
}
