//
// Created by diego on 14/11/19.
//

#include "ComandoEliminar.h"

ComandoEliminar::ComandoEliminar(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador)
        : ComandoVisualizacion(desplazables, renderizador) {}

void ComandoEliminar::ejecutar(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    if(it == desplazables.end()){
        eventos.erase(eventos.begin());
        return;
    }
    eventos.erase(eventos.begin());
    it->second->eliminar();
    delete(it->second);
    desplazables.erase(it);
}
