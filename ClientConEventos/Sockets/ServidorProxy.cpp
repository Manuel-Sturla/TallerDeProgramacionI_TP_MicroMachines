//
// Created by manfer on 31/10/19.
//

#include "ServidorProxy.h"
#include "SocketActivo.h"
#include "Utilidades.h"

#define SEPARADOR ';'

#define CMD_PARTIDAS "PAR"
#define MSJ_FIN "F"

#define MSJ_COMIENZO_PARTIDA "PartidaComienza"

ServidorProxy::ServidorProxy(const std::string &host, const std::string &servicio):
        protocolo(std::move(SocketActivo(host, servicio))){
}

void ServidorProxy::ejecutarMovimiento(const std::string& comando) {
    protocolo.enviar(comando);
}

void ServidorProxy::elegirPartida(const std::string &nombre) {
    protocolo.enviar("UnirPAR");
    protocolo.enviar(nombre);
}

void ServidorProxy::crearPartida(const std::string &nombre, const std::string& cantJugadores) {
    protocolo.enviar("CrearPAR");
    std::vector<std::string> aux ={nombre, cantJugadores};
    protocolo.enviar(unir(aux, SEPARADOR));
}

std::vector<std::string> ServidorProxy::obtenerPartidas() {
    protocolo.enviar("PAR");
    std::vector<std::string> resultado;
    std::string aux = protocolo.recibir();
    resultado = separar(aux, ';');
    resultado.erase(resultado.begin());
    return resultado;
}

std::vector<std::string> ServidorProxy::obtenerMapa() {
    std::vector<std::string> resultado;
    while (protocolo.recibir() != MSJ_COMIENZO_PARTIDA){
        //Recibe las conexiones de los otros jugadores y temporalmente las ignora
    }
    std::string aux;
    while ((aux = protocolo.recibir()) != MSJ_FIN){
        resultado.push_back(aux);
    }
    return resultado;
}

void ServidorProxy::terminarConexion() {
    protocolo.terminarConexion();
}

std::vector<std::string> ServidorProxy::obtenerEventosJuego() {
    std::vector<std::string> eventos;
    std::vector<std::string> aux = obtenerEvento();
    while(aux[0] != "fin simulacion"){
        for(auto & i : aux){
            eventos.emplace_back(i);
        }
        aux = obtenerEvento();
    }
    return eventos;
}

std::vector<std::string> ServidorProxy::obtenerEvento() {
    std::string aux = protocolo.recibir();
    std::vector<std::string> evento = separar(aux, ',');
    return evento;
}

std::vector<std::string> ServidorProxy::obtenerMiAuto() {
    std::vector<std::string> evento = obtenerEvento();
    while(evento[0] != "posicionarAuto"){
        evento = obtenerEvento();
    }
    return evento;
}

