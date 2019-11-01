//
// Created by manfer on 31/10/19.
//

#include <sstream>
#include "ClienteProxy.h"
#include "Utilidades.h"

#define SEPARADOR ';'

ClienteProxy::ClienteProxy(SocketAmigo socketCliente) : protocolo(std::move(socketCliente)){

}

std::string ClienteProxy::obtenerComando() {
    return protocolo.recibir();
}


std::vector<std::string> ClienteProxy::obtenerPartida() {
    std::string mensaje = protocolo.recibir();
    return separar(mensaje, SEPARADOR);
}
