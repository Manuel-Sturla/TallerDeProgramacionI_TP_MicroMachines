//
// Created by manfer on 31/10/19.
//

#include <iostream>
#include "ServidorProxy.h"
#include "SocketActivo.h"
#include "Utilidades.h"

#define SEPARADOR ';'

#define CMD_PARTIDAS "PAR"
#define CMD_POSICIONES "POS"
#define CMD_MAPA "MAP"
#define CMD_MOVIMIENTO "MOV"
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
    std::vector<std::string> aux ={"CrearPAR", nombre, cantJugadores};
    protocolo.enviar(unir(aux, SEPARADOR));
}

std::vector<std::string> ServidorProxy::obtenerPartidas() {
    protocolo.enviar(CMD_PARTIDAS);
    std::vector<std::string> resultado;
    std::string aux;
    while ((aux = protocolo.recibir()) != MSJ_FIN){
        resultado.push_back(aux);
    }
    return resultado;
}

void ServidorProxy::obtenerPosiciones(std::vector<std::string> &extras, std::vector<std::string> &autos) {
    std::string aux;
    while ((aux = protocolo.recibir()) != MSJ_FIN){
        //Aca se podría desempaquetar o desparsear los datos...
        //Tal vez podría armar con esos datos un struct o algo asi.
        extras.push_back(aux);
    }
    while ((aux = protocolo.recibir()) != MSJ_FIN){
        autos.push_back(aux);
    }
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
