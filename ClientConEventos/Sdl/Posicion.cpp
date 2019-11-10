//
// Created by diego on 24/10/19.
//

#include <iostream>
#include "Posicion.h"

Posicion::Posicion(float posX, float posY, float ancho, float altura, int angulo) {
    posicion.x = posX;
    posicion.y = posY;
    posicion.w = ancho;
    posicion.h = altura;
    this->angulo = angulo;
    valida = true;
}

pos_t Posicion::getPosicion() {
    return posicion;
}

void Posicion::moverA(float posX, float posY) {
    posicion.x = posX;
    posicion.y = posY;
}

void Posicion::rotar(int angulo) {
    this->angulo = angulo;
}

int Posicion::getAngulo() {
    return angulo;
}

bool Posicion::esValida() {
    return valida;
}

void Posicion::invalidar() {
    valida = false;
}
