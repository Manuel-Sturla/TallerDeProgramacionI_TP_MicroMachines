#include <iostream>
#include "Protocolo.h"
#define LONG_EN_BYTES 1
void Protocolo::enviar(const std::string &mensaje) {
    socket.enviarLongitud(mensaje.length());
    socket.enviar(mensaje);
}

std::string Protocolo::recibir() {
    size_t longitud = socket.recibirLongitud();
    std::string mensaje;
    socket.recibir(mensaje, longitud);
    return mensaje;
}

Protocolo::Protocolo(SocketAmigo socketAmigo) :socket(std::move(socketAmigo)){

}

Protocolo &Protocolo::operator=(Protocolo &&otro) {
    if (this == &otro) {
        return *this;
    }
    this->socket = std::move(otro.socket);
    return *this;
}

void Protocolo::terminarConexion() {
    socket.cerrar();
}