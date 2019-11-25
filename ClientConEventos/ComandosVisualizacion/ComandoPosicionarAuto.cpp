//
// Created by diego on 14/11/19.
//

#include "ComandoPosicionarAuto.h"
#include "../Juego/Auto.h"

ComandoPosicionarAuto::ComandoPosicionarAuto(std::map<std::string, Desplazable*>& desplazables,Renderizador &renderizador, std::string idMiAuto):\
 ComandoVisualizacion(desplazables, renderizador), idMiAuto(idMiAuto) {}

void ComandoPosicionarAuto::ejecutar(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    bool esMiAuto = (eventos[0] == idMiAuto);
    if(it == desplazables.end()){
        desplazables.emplace(eventos[0], new Auto(renderizador, 1, eventos[0], false));
        it = desplazables.find(eventos[0]);
    }
    eventos.erase(eventos.begin());
    it->second->mover(std::stof(eventos[0]), (-1)*std::stof(eventos[1]), std::stoi(eventos[2]));
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
    if(esMiAuto){
        it->second->modificar(eventos[0]);
    }
    eventos.erase(eventos.begin());
}
