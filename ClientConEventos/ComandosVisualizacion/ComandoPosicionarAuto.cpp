//
// Created by diego on 14/11/19.
//

#include "ComandoPosicionarAuto.h"
#include "../Juego/Auto.h"

ComandoPosicionarAuto::ComandoPosicionarAuto(std::map<std::string, Desplazable*>& desplazables,
                                             Renderizador &renderizador) : ComandoVisualizacion(desplazables, renderizador) {}

void ComandoPosicionarAuto::ejecutar(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    if(it == desplazables.end()){
        desplazables.emplace(eventos[0], new Auto(renderizador, 1, eventos[0]));
        it = desplazables.find(eventos[0]);
    }
    eventos.erase(eventos.begin());
    it->second->mover(std::stof(eventos[0]), (-1)*std::stof(eventos[1]), std::stoi(eventos[2]));
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
    it->second->modificar(eventos[0]);
    eventos.erase(eventos.begin());
}
