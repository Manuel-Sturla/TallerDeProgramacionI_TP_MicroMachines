//
// Created by diego on 9/11/19.
//

#include "Extra.h"
#include "../Excepciones/ExcepcionConPos.h"

Extra::Extra(Renderizador &renderizador, int tam, std::string tipo) : Desplazable(renderizador, tam) {
    if(tipo == "Barro"){
        id = renderizador.agregarTrecho("../Sprites/barro.png", &posicion);
    } else {
        throw ExcepcionConPos(__FILE__, __LINE__, "Tipo de extra invalido");
    }
}

void Extra::mover(float posX, float posY, int angulo) {
    posicion.moverA(posX, posY);
}

void Extra::morir() {}

void Extra::modificar(std::string &mensaje) {

}

void Extra::eliminar() {
    renderizador.borrarTrecho(id);
}
