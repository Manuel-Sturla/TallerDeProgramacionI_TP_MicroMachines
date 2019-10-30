//
// Created by diego on 28/10/19.
//

#include "Auto.h"
#include "../Sdl/Renderizador.h"

Auto::Auto(Renderizador& renderizador, int tam) : posicion(0,0, tam, tam, 0){
    renderizador.agregarTextura("auto.png", &posicion);
}

void Auto::mover(int &posX, int &posY, int &angulo) {
    posicion.moverA(posX, posY);
    posicion.rotar(angulo);
}

Posicion &Auto::getPos() {
    return posicion;
}
