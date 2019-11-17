//
// Created by diego on 17/11/19.
//

#include "ComandoPodio.h"

ComandoPodio::ComandoPodio(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador,bool &keepTalking)\
: ComandoVisualizacion(desplazables, renderizador), keepTalking(keepTalking), posPodio(0,200,100,1000,-90) {}

void ComandoPodio::ejecutar(std::vector<std::string> &eventos) {
    renderizador.borrarTodo();
    renderizador.agregarTexto(eventos[0], &posPodio);
    keepTalking = false;
}
