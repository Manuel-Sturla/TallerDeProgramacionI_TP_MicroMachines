//
// Created by manfer on 31/10/19.
//

#include "Protocolo.h"
#define LONG_EN_BYTES 1
void Protocolo::enviar(const std::string &mensaje) {
    char longitud = mensaje.length();
    socket.enviar(&longitud);
    socket.enviar(mensaje);
}

std::string Protocolo::recibir() {
    std::string msj_longitud;
    socket.recibir(msj_longitud, LONG_EN_BYTES);
    auto longitud = static_cast<size_t>(*msj_longitud.c_str());
    std::string mensaje;
    socket.recibir(mensaje, longitud);
    return mensaje;
}

Protocolo::Protocolo(SocketAmigo socketAmigo) :socket(std::move(socketAmigo)){

}

Protocolo::Protocolo(Protocolo &&otro): socket(std::move(otro.socket)) {
}

Protocolo &Protocolo::operator=(Protocolo &&otro) {
    if (this == &otro) {
        return *this;
    }
    this->socket = std::move(otro.socket);
    return *this;
}
