#include <iostream>
#include "Objeto.h"

void Objeto::empaquetarPosicion(std::vector<std::string> *destino) {
    b2Vec2 posicion = cuerpo -> GetPosition();
    destino -> emplace_back(std::to_string(posicion.x));
    destino -> emplace_back(std::to_string(posicion.y));
}

void Objeto::empaquetarAngulo(std::vector<std::string> *destino) {
    destino -> emplace_back(std::to_string(cuerpo -> GetAngle() * 180 / b2_pi));
}
