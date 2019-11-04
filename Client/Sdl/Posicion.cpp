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
}

pos_t Posicion::getPosicion() {
    std::unique_lock<std::mutex> l(mutex);
    return posicion;
}

void Posicion::moverA(float posX, float posY) {
    std::unique_lock<std::mutex> l(mutex);
    posicion.x = posX;
    posicion.y = posY;
}

void Posicion::rotar(int angulo) {
    this->angulo = angulo;
}

int Posicion::getAngulo() {
    return angulo;
}
/*
bool Posicion::estaEnRango(int ancho, int largo) {
    if(posicion.x - posicion.w < 0 || posicion.x > ancho){
        return false;
    }
    return !((posicion.y - posicion.h) < 0 || posicion.y > largo);
}
*/