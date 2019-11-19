//
// Created by diego on 14/11/19.
//

#include "ComandoPosicionarExtra.h"
#include "../Juego/Extra.h"

ComandoPosicionarExtra::ComandoPosicionarExtra(std::map<std::string, Desplazable *> &desplazables, Renderizador& renderizador)
        : ComandoVisualizacion(desplazables, renderizador) {}

void ComandoPosicionarExtra::ejecutar(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    if(it == desplazables.end()){
        desplazables.emplace(eventos[0], new Extra(renderizador, 1, eventos[1], eventos[0]));
        it = desplazables.find(eventos[0]);
        eventos.erase(eventos.begin());
    } else {
        eventos.erase(eventos.begin());
    }
    eventos.erase(eventos.begin());
    it->second->mover(std::stof(eventos[0]), (-1)*std::stof(eventos[1]), 0);
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
}
