//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "Visualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../Sdl/Sonido.h"

#define ANCHO_PANTALLA 1000
#define ALTURA_PANTALLA 1000

Visualizacion::Visualizacion(ServidorProxy &servidor, std::shared_ptr<Jugador> &jugador) : servidor(servidor),\
renderizador("microMachines.exe", ANCHO_PANTALLA, ALTURA_PANTALLA, m) {
    enJuego = false;
    keepTalking = true;
    receptor = new HiloReceptor(renderizador, servidor, keepTalking, enJuego, m, jugador);
    lector = new HiloLector(servidor, keepTalking, jugador);
    receptor->start();
    lector->start();
}

void Visualizacion::ejecutarPartida() {
    try{
//        Sonido sonido("../abba.wav");
        while(keepTalking && enJuego) {
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

void Visualizacion::esperarInicioPartida() {
    try {
        while(!enJuego && keepTalking){
            renderizador.limpiar();
            renderizador.copiarTodo();
            renderizador.imprimir(100);
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

Visualizacion::~Visualizacion() {
    if(receptor != nullptr){
        receptor->join();
        delete(receptor);
        receptor = nullptr;
    }
    if(lector != nullptr){
        lector->join();
        delete(lector);
        lector = nullptr;
    }
}
