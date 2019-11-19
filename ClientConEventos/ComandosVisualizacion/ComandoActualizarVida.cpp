//
// Created by diego on 18/11/19.
//

#include "ComandoActualizarVida.h"

ComandoActualizarVida::ComandoActualizarVida(std::map<std::string, Desplazable *> &desplazables,\
Renderizador &renderizador, std::string& idMiAuto) : ComandoVisualizacion(desplazables,renderizador),\
posVida(10, 900, 100,40, 0), idMiAuto(idMiAuto) {
    idVida = "vida";
}

void ComandoActualizarVida::ejecutar(std::vector<std::string> &eventos) {
    if(eventos[0] == idMiAuto){
        renderizador.borrarTexto(idVida);
        renderizador.agregarTexto("Vida: " + eventos[1], &posVida, idVida);
    }
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
}
