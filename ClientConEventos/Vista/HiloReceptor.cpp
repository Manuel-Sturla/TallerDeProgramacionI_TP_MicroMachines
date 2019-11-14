//
// Created by diego on 2/11/19.
//

#include <iostream>
#include "HiloReceptor.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "Camara.h"
#include "../Sockets/SocketPeerException.h"
#include "../Jugador/JugadorCPU.h"

HiloReceptor::HiloReceptor(Renderizador &renderizador, ServidorProxy &servidor, bool &keepTalking, bool &enJuego,
                           std::mutex &m, std::shared_ptr<Jugador> &jugador) : keepTalking(keepTalking), servidor(servidor),\
admin(renderizador, m, keepTalking), enJuego(enJuego), jugador(jugador) {}

void HiloReceptor::run() {
    try {
        esperarInicioPartida();
        while(keepTalking && enJuego){
            std::vector<std::string> eventos;
            eventos = servidor.obtenerEventosJuego();
            admin.ejecutarEventos(eventos);
        }
    } catch (const SocketPeerException& e){
        keepTalking = false;
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

void HiloReceptor::esperarInicioPartida() {
    std::vector<std::string> evento;
    evento = servidor.obtenerEvento();
    while(evento[0] != "inicioPartida" && keepTalking){
        admin.actualizarJugadores(evento);
        evento = servidor.obtenerEvento();
    }
    evento = servidor.obtenerMapa();
    admin.crearPista(evento);
    if (jugador->esCpu()){
        std::shared_ptr<JugadorCPU> jug = std::dynamic_pointer_cast<JugadorCPU>(jugador);
        jug->ponerMapa(evento);
    }
    evento = servidor.obtenerMiAuto();
    Desplazable* miAuto = admin.crearMiAuto(evento);
    if (jugador->esCpu()){
        std::shared_ptr<JugadorCPU> jug = std::dynamic_pointer_cast<JugadorCPU>(jugador);
        jug->ponerAuto(miAuto);
    }
    enJuego = true;
}
