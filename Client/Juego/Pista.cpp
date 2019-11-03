//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "Pista.h"
#include "../Excepciones/ExcepcionConPos.h"

Pista::Pista(Renderizador &renderizador) : renderizador(renderizador) {
    tamImagen = 0;
}

void Pista::crear(std::vector<std::string> mensaje) {
    if(mensaje.empty()){
        throw ExcepcionConPos(__FILE__, __LINE__, "Mensaje incompleto");
    }
    tamImagen = std::stoi(mensaje[0]);
    mensaje.erase(mensaje.begin());
    if(mensaje.size()%4 != 0){
        tamImagen = 0;
        throw ExcepcionConPos(__FILE__, __LINE__, "Mensaje incompleto");
    }
    for(unsigned long i = 0; i < mensaje.size()/4; ++i){
        if(mensaje[4*i] == "Asfalto"){
            agregarRecta(std::stoi(mensaje[4*i+1]), -1*std::stoi(mensaje[4*i+2]), std::stoi(mensaje[4*i+3]));
        } else if(mensaje[4*i] == "Curva"){
            agregarCurva(std::stoi(mensaje[4*i+1]), -1*std::stoi(mensaje[4*i+2]), std::stoi(mensaje[4*i+3]));
        } else if(mensaje[4*i] == "Pasto"){
            agregarPasto(std::stoi(mensaje[4*i+1]), -1*std::stoi(mensaje[4*i+2]), std::stoi(mensaje[4*i+3]));
        } else {
            throw ExcepcionConPos(__FILE__, __LINE__, "Tipo de pista invalido" + mensaje[i]);
        }
    }
}

void Pista::agregarRecta(int posX, int posY, int angulo) {
    pistaPos.push_back(new Posicion(posX, posY, tamImagen, tamImagen, angulo));
    renderizador.agregarTrecho("pista.png", pistaPos[pistaPos.size()-1]);
}

void Pista::agregarCurva(int posX, int posY, int angulo) {
    pistaPos.push_back(new Posicion(posX, posY, tamImagen, tamImagen, angulo));
    renderizador.agregarTrecho("pasto.png", pistaPos[pistaPos.size()-1]);
    renderizador.agregarTrecho("curva.png", pistaPos[pistaPos.size()-1]);
}

void Pista::agregarPasto(int posX, int posY, int angulo) {
    pistaPos.push_back(new Posicion(posX, posY, tamImagen, tamImagen, angulo));
    renderizador.agregarTrecho("pasto.png", pistaPos[pistaPos.size()-1]);
}

Pista::~Pista() {
    for(auto pos : pistaPos){
        delete(pos);
    }
}
