//
// Created by diego on 17/11/19.
//

#include "ComandoGanador.h"

ComandoGanador::ComandoGanador(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador,\
bool &keepTalking, std::string idMiAuto) : ComandoVisualizacion(desplazables, renderizador), keepTalking(keepTalking),\
posPodio(0,200,renderizador.obtenerAncho(),renderizador.obtenerAltura()/10,0), idMiAuto(idMiAuto) {
    idGanador = "ganador";
}

void ComandoGanador::ejecutar(std::vector<std::string> &eventos) {
    renderizador.borrarTodo();
    if(eventos[0] == idMiAuto){
        renderizador.agregarTexto("Felicitaciones! Ganaste!", &posPodio, idGanador, 255, 215, 0);
    } else{
        renderizador.agregarTexto("Gano el jugador"+eventos[0], &posPodio, idGanador, 255, 255, 255);
    }
    keepTalking = false;
}
