//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "HiloVisualizacion.h"

HiloVisualizacion::HiloVisualizacion(Servidor& servidor) : renderizador("microMachines.exe", 1000, 1000), servidor(servidor) {
    Posicion posPista(0, 0, 1000, 1000);
    renderizador.agregarTextura("pista.png", posPista, "pista");
    Posicion posAuto(260, 0, 100, 100);
    renderizador.agregarTextura("auto.png", posAuto, "auto");
}

void HiloVisualizacion::run() {
    std::vector<int> mensaje = servidor.recibir();
    while(mensaje[0] != -1){
        renderizador.limpiar();
        renderizador.copiar("pista");
        renderizador.mover("auto", mensaje[0], mensaje[1]);
        renderizador.imprimir(20);
        mensaje = servidor.recibir();
    }
}
