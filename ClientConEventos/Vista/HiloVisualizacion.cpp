//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "HiloVisualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"
#define ANCHO_PANTALLA 1000
#define ALTURA_PANTALLA 1000

HiloVisualizacion::HiloVisualizacion(ServidorProxy& servidor, bool& keepTalking) : servidor(servidor),\
renderizador("microMachines.exe", ANCHO_PANTALLA, ALTURA_PANTALLA), keepTalking(keepTalking) {
    this->receptor = nullptr;
    enJuego = false;
}

void HiloVisualizacion::run() {
    try{
        receptor = new HiloReceptor(renderizador, servidor, keepTalking, enJuego);
        receptor->start();
        esperarInicioPartida();
        while(keepTalking) {
            renderizador.limpiar();
            renderizador.copiarTodo();
            renderizador.imprimir(20);
        }
    } catch(const ExcepcionConPos& e){
        keepTalking = false;
        std::cerr<<e.what()<<'\n';
    } catch (std::exception& e) {
        keepTalking = false;
        std::cerr<<e.what()<<'\n';
    } catch (...) {
        keepTalking = false;
        std::cerr<<"Error desconocido\n";
    }
}

HiloVisualizacion::~HiloVisualizacion() {
    if(receptor != nullptr){
        receptor->join();
        delete(receptor);
    }
}

void HiloVisualizacion::esperarInicioPartida() {
    while(!enJuego){
        renderizador.limpiar();
        renderizador.copiarTodo();
        renderizador.imprimir(100);
    }
}
