#include "SocketPeerException.h"

SocketPeerException::SocketPeerException(std::string mensaje, std::string error, std::string archivo, int linea)
        : SocketException(mensaje, error, archivo, linea) {

}

