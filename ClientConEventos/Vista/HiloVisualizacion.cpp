//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "HiloVisualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"

HiloVisualizacion::HiloVisualizacion(ServidorProxy& servidor, bool& keepTalking) : servidor(servidor),\
renderizador("microMachines.exe", 1000, 1000), pista(renderizador),\
camara(1000, 100), keepTalking(keepTalking) {
    this->receptor = nullptr;
}

void HiloVisualizacion::run() {
    try{
        pista.crear(servidor.obtenerMapa());
        receptor = new HiloReceptor(renderizador, servidor, camara, keepTalking);
        receptor->start();
        while(keepTalking) {
            renderizador.limpiar();
            renderizador.copiarTodo(camara);
            renderizador.imprimir(20);
        }
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
    } catch (...) {
        std::cerr<<"Error desconocido\n";
    }
}

HiloVisualizacion::~HiloVisualizacion() {
    if(receptor != nullptr){
        receptor->join();
        delete(receptor);
    }
}
