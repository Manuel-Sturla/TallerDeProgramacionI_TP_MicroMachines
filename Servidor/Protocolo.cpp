#include "Protocolo.h"
#define LONG_EN_BYTES 1
void Protocolo::enviar(const std::string &mensaje) {
    char longitud = mensaje.length();
    std::string l_s (1,longitud);
    socket.enviar(l_s);
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
