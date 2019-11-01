//
// Created by manfer on 31/10/19.
//

#include <SocketActivo.h>
#include "ServidorProxy.h"
#include "Utilidades.h"
#define SEPARADOR ';'

ServidorProxy::ServidorProxy(const std::string &host, const std::string &servicio):
protocolo(std::move(SocketActivo(host, servicio))){
}

void ServidorProxy::ejecutarComando(const std::string& comando) {
    protocolo.enviar(comando);
}

void ServidorProxy::elegirPartida(const std::string &nombre) {
    protocolo.enviar(nombre);
}

void ServidorProxy::crearPartida(const std::string &nombre, const int& cantJugadores) {
    std::vector<std::string> aux ={nombre, std::to_string(cantJugadores)};
    protocolo.enviar(unir(aux, SEPARADOR));
}
