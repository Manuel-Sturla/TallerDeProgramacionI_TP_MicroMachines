//
// Created by diego on 9/11/19.
//

#include "Extra.h"
#include "../Excepciones/ExcepcionConPos.h"

Extra::Extra(Renderizador &renderizador, int tam, std::string tipo) : Desplazable(renderizador, tam) {
    if(tipo == "Barro"){
        id = renderizador.agregarTextura("../Sprites/barro.png", &posicion);
    } else {
        throw ExcepcionConPos(__FILE__, __LINE__, "Tipo de extra invalido");
    }
}

void Extra::mover(float posX, float posY, int angulo) {
    posicion.moverA(posX, posY);
}

void Extra::morir() {
//    posicion.invalidar(); //sacar y usar borrar textura.
}

void Extra::modificar(std::string &mensaje) {}

void Extra::eliminar() {}
