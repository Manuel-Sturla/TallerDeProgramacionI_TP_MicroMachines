//
// Created by diego on 28/10/19.
//

#include <iostream>
#include "ContenedorDeTexturas.h"

ContenedorDeTexturas::ContenedorDeTexturas(Renderizador& renderizador, Servidor& servidor)\
: servidor(servidor), pista(renderizador, servidor.iniciarPista()), miAuto(renderizador, 100) {}

bool ContenedorDeTexturas::actualizar() {
    std::vector<std::string> mensaje = servidor.recibir();
    if(mensaje[0] == "terminar"){
        return false;
    }
    int posX = std::stoi(mensaje[0]);
    int posY = std::stoi(mensaje[1]);
    int angulo = std::stoi(mensaje[2]);
    miAuto.mover(posX, posY, angulo);
    return true;
}

Auto& ContenedorDeTexturas::getAuto() {
    return miAuto;
}
