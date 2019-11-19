//
// Created by diego on 9/11/19.
//

#include "Extra.h"
#include "../Excepciones/ExcepcionConPos.h"

Extra::Extra(Renderizador &renderizador, int tam, const std::string& tipo, std::string id) : Desplazable(renderizador, tam, id) {
    if(tipo == "Barro"){
        renderizador.agregarExtra("../Sprites/barro.png", &posicion, id);
    } else if(tipo == "Aceite") {
        renderizador.agregarExtra("../Sprites/aceite.png", &posicion, id);
    } else if(tipo == "Boost") {
        renderizador.agregarExtra("../Sprites/boost.png", &posicion, id);
    } else if(tipo == "Piedra") {
        renderizador.agregarExtra("../Sprites/piedra.png", &posicion, id);
    } else if(tipo == "Salud") {
        renderizador.agregarExtra("../Sprites/salud.png", &posicion, id);
    } else {
        throw ExcepcionConPos(__FILE__, __LINE__, "Tipo de extra invalido");
    }
}

void Extra::mover(float posX, float posY, int angulo) {
    posicion.moverA(posX, posY);
}

void Extra::morir() {}

void Extra::modificar(std::string &mensaje) {}

void Extra::eliminar() {
    renderizador.borrarExtra(id);
}
