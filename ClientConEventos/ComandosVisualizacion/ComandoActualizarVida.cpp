//
// Created by diego on 18/11/19.
//

#include "ComandoActualizarVida.h"

ComandoActualizarVida::ComandoActualizarVida(std::map<std::string, Desplazable *> &desplazables,\
Renderizador &renderizador, std::string& idMiAuto) : ComandoVisualizacion(desplazables,renderizador),\
posVida(10, renderizador.obtenerAltura()-100, renderizador.obtenerAncho()/5,renderizador.obtenerAltura()/20, 0),\
idMiAuto(idMiAuto) {
    idVida = "vida";
}

void ComandoActualizarVida::ejecutar(std::vector<std::string> &eventos) {
    if(eventos[0] == idMiAuto){
        renderizador.borrarTexto(idVida);
        renderizador.agregarTexto("Vida: " + eventos[1], &posVida, idVida, 255, 255, 255);
    }
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
}
