//
// Created by diego on 22/10/19.
//

#include <string>
#include "Servidor.h"

void Servidor::enviar(const std::string& mensaje) {
    if(mensaje == "acelerar"){
        posY -= 20;
    } else if(mensaje == "frenar"){
        posY += 20;
    } else if(mensaje == "doblar derecha"){
        angulo += 30;
        posX += 5;
    } else if(mensaje == "doblar izquierda"){
        angulo -= 30;
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
    aux.push_back(angulo);
    return aux;
}

Servidor::Servidor(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    this->angulo = 0;
}
