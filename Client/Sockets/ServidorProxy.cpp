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

ServidorProxy::ServidorProxy(const std::string &host, const std::string &servicio):
        protocolo(std::move(SocketActivo(host, servicio))){
}

void ServidorProxy::ejecutarMovimiento(const std::string& comando) {
    protocolo.enviar(CMD_MOVIMIENTO);
    protocolo.enviar(comando);
}

void ServidorProxy::elegirPartida(const std::string &nombre) {
    protocolo.enviar(nombre);
}

void ServidorProxy::crearPartida(const std::string &nombre, const int& cantJugadores) {
    std::vector<std::string> aux ={nombre, std::to_string(cantJugadores)};
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
    protocolo.enviar(CMD_POSICIONES);
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
    protocolo.enviar(CMD_MAPA);
    std::vector<std::string> resultado;
    std::string aux;
    while ((aux = protocolo.recibir()) != MSJ_FIN){
        resultado.push_back(aux);
    }
    return resultado;
}

bool ServidorProxy::creePartida() {
    return protocolo.recibir() == "iniciar partida";
}

void ServidorProxy::terminarConexion() {
    protocolo.terminarConexion();
}
