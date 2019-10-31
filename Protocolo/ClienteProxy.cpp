//
// Created by manfer on 31/10/19.
//

#include <sstream>
#include "ClienteProxy.h"

#define SEPARADOR ';'

ClienteProxy::ClienteProxy(SocketAmigo socketCliente) : protocolo(socketCliente){

}

std::string ClienteProxy::obtenerComando() {
    return protocolo.recibir();
}

std::vector<std::string> split(std::string& cadena, char sep){
    std::vector<std::string> resultado;
    std::istringstream iss(cadena);
    while(iss.good()){
        std::string aux;
        std::getline(iss, aux, sep);
        resultado.push_back(aux);
    }
    return resultado;
}
std::vector<std::string> ClienteProxy::obtenerPartida() {
    std::string mensaje = protocolo.recibir();
    return split(mensaje, SEPARADOR);
}
