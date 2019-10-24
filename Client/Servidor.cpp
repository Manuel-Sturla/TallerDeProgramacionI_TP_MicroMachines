//
// Created by diego on 22/10/19.
//

#include <string>
#include "Servidor.h"

void Servidor::enviar(const std::string& mensaje) {
    if(mensaje == "acelerar"){
        posY -= 5;
    } else if(mensaje == "frenar"){
        posY += 5;
    } else if(mensaje == "doblar derecha"){
        posX += 5;
    } else if(mensaje == "doblar izquierda"){
        posX -= 5;
    } else if(mensaje == "cerrar"){
        posX = -1;
        posY = -1;
    }
}

std::vector<int> Servidor::recibir() {
    std::vector<int> aux;
    aux.push_back(posX);
    aux.push_back(posY);
    return aux;
}

Servidor::Servidor(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}
