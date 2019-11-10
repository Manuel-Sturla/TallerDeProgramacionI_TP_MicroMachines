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
}

void HiloVisualizacion::run() {
    try{
        bool enJuego = false;
        receptor = new HiloReceptor(renderizador, servidor, keepTalking, enJuego);
        receptor->start();
        esperarInicioPartida(enJuego);
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

void HiloVisualizacion::esperarInicioPartida(bool &enJuego) {
    Posicion posicion(0,0, ANCHO_PANTALLA, ALTURA_PANTALLA, 0);
    renderizador.agregarTrecho("../inicio.jpeg", &posicion);
    while(!enJuego){
        renderizador.limpiar();
        renderizador.copiarTodo();
        renderizador.imprimir(100);
    }
    posicion.invalidar();
}
