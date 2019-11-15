#include <iostream>
#include "Protocolo.h"

void Protocolo::enviar(const std::string &mensaje) {
    socket.enviarLongitud(mensaje.length());
    socket.enviar(mensaje);
}

std::string Protocolo::recibir() {
    size_t longitud = socket.recibirLongitud();
    std::string mensaje;
    socket.recibir(mensaje, longitud);
    std::cout << "Recibi: " << mensaje << std::endl;
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

void Protocolo::terminarConexion() {
    socket.cerrar();
}