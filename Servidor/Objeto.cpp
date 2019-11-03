#include <iostream>
#include "Objeto.h"

void Objeto::empaquetarPosicion(std::vector<std::string> *destino) {
  b2Vec2 posicion = cuerpo -> GetPosition();
  std::cout << "Posicion " << posicion.x << " " << posicion.y << std::endl;
  destino -> emplace_back(std::to_string(posicion.x));
  destino -> emplace_back(std::to_string(posicion.y));
}

void Objeto::empaquetarAngulo(std::vector<std::string> *destino) {
    std::cout << "Angulo " << cuerpo -> GetAngle() << std::endl;
  destino -> emplace_back(std::to_string(cuerpo -> GetAngle()));
}
