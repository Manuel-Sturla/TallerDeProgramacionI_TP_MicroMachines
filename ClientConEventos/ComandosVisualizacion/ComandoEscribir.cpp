//
// Created by diego on 14/11/19.
//

#include "ComandoEscribir.h"

ComandoEscribir::ComandoEscribir(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador)
        : ComandoVisualizacion(desplazables, renderizador), posTexto(0,200,100,1000,-90) {}

void ComandoEscribir::ejecutar(std::vector<std::string> &eventos) {

}
