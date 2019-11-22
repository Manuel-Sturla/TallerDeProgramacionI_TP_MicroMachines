//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "Visualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../Sdl/Sonido.h"

Visualizacion::Visualizacion(ServidorProxy &servidor, std::shared_ptr<Jugador> &jugador, int anchoPantalla,
                             int alturaPantalla, int fpsRenderizacion, int aumentoCamara) : servidor(servidor),\
renderizador("microMachines.exe", anchoPantalla, alturaPantalla, m, aumentoCamara) {
    this->fpsRenderizacion = fpsRenderizacion;
    enJuego = false;
    keepTalking = true;
    receptor = new HiloReceptor(renderizador, servidor, keepTalking, enJuego, m, jugador, fpsRenderizacion);
    lector = new HiloLector(servidor, keepTalking, jugador, fpsRenderizacion);
    receptor->start();
    lector->start();
}

void Visualizacion::ejecutarPartida() {
    try{
//        Sonido sonido("../abba.wav");
        while(keepTalking && enJuego) {
            renderizador.limpiar();
            renderizador.copiarTodo();
            renderizador.imprimir(1000/fpsRenderizacion);
        }
        renderizador.limpiar();
        renderizador.copiarTodo();
        renderizador.imprimir((1000/fpsRenderizacion)*10);
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
