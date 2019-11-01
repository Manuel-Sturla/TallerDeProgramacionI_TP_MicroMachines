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
        posX += 20;
    } else if(mensaje == "doblar izquierda"){
        angulo -= 30;
        posX -= 20;
    } else if(mensaje == "cerrar"){
        posX = -1;
        posY = -1;
    }
}

std::vector<std::string> Servidor::recibir() {
    std::vector<std::string> aux;
    if(posX == -1){
        aux.emplace_back("terminar");
    }
    aux.emplace_back(std::to_string(posX));
    aux.emplace_back(std::to_string(posY));
    aux.emplace_back(std::to_string(angulo));
    return aux;
}

Servidor::Servidor(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    this->angulo = 0;
}

void agregarTrecho(std::string tipo, int posX, int posY, int angulo, std::vector<std::string>& mensaje){
    mensaje.emplace_back(tipo);
    mensaje.emplace_back(std::to_string(posX));
    mensaje.emplace_back(std::to_string(posY));
    mensaje.emplace_back(std::to_string(angulo));
}

std::vector<std::string> Servidor::iniciarPista() {
    std::vector<std::string> mensaje;
    mensaje.emplace_back("1000");
    agregarTrecho("recta", 0, 0, 90, mensaje);
    agregarTrecho("recta", 0, -1000, 90, mensaje);
    agregarTrecho("curva", 0, -2000, 90, mensaje);
    agregarTrecho("pasto", 0, -3000, 90, mensaje);
    return mensaje;
}
