//
// Created by diego on 14/11/19.
//

#include "ComandoMorir.h"

ComandoMorir::ComandoMorir(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador)\
: ComandoVisualizacion(desplazables, renderizador) {}

void ComandoMorir::ejecutar(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    eventos.erase(eventos.begin());
    if(it != desplazables.end()){
        it->second->morir();
    }
}
