//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "Visualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../Sdl/Sonido.h"

Visualizacion::Visualizacion(ServidorProxy &servidor, std::shared_ptr<Jugador> &jugador, int anchoPantalla,
                             int alturaPantalla, int fpsRenderizacion, int aumentoCamara) : servidor(servidor),\
renderizador("microMachines.exe", anchoPantalla, alturaPantalla, m, aumentoCamara),
grabador(renderizador){
    this->fpsRenderizacion = fpsRenderizacion;
    enJuego = false;
    keepTalking = true;
    receptor = new HiloReceptor(renderizador, servidor, keepTalking, enJuego, m, jugador, fpsRenderizacion);
    lector = new HiloLector(servidor, keepTalking, jugador, fpsRenderizacion, grabador);
    receptor->start();
    lector->start();
}

void Visualizacion::ejecutarPartida() {
    try{
        Sonido sonido("../abba.wav");
    	std::chrono::high_resolution_clock::time_point t2;
    	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    	int espera = 0;
//    	grabador.grabarVideo("Videazo.mpeg");
        while(keepTalking && enJuego) {
            renderizador.limpiar();
            renderizador.copiarTodo();
            if (grabador.estaGrabando()){
                grabador.obtenerDatosTextura();
            }
            t2 = std::chrono::high_resolution_clock::now();
            espera += (1000/fpsRenderizacion) - std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
            if(espera < 0){
                t1 = t2;
            	continue;
            } else {
	            renderizador.imprimir(espera);
	            t1 = t2 + std::chrono::milliseconds(espera);
	        	espera = 0;
            }
        }
        if (grabador.estaGrabando()){
            grabador.terminar();
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
