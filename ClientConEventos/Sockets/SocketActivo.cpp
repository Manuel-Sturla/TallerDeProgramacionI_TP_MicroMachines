#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include "SocketActivo.h"
#include "SocketPeerException.h"

SocketActivo::SocketActivo(): SocketAmigo(-1) {
}

void SocketActivo::conectar(const std::string &hostName, const std::string &service) {
    struct addrinfo hints;
    struct addrinfo *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    int errcheck = getaddrinfo(hostName.c_str(), service.c_str(), & hints, & result);
    if (errcheck != 0) {
        throw SocketPeerException("Error al conectar: ",strerror(errno), __FILE__, __LINE__);
    }
    fd = conseguirConexion(result);
    freeaddrinfo(result);
}

int SocketActivo::conseguirConexion(struct addrinfo *result) {
    int aFd = -1;
    bool connected = false;
    struct addrinfo *ptr;
    for (ptr = result; ptr != nullptr && !connected; ptr = ptr -> ai_next) {
        aFd = socket(ptr -> ai_family, ptr -> ai_socktype, ptr -> ai_protocol);
        if (aFd == -1) {
            throw SocketPeerException("Error al crear socket: ", strerror(errno), __FILE__, __LINE__);
        } else{
            int errcheck = ::connect(aFd, ptr -> ai_addr, ptr -> ai_addrlen);
            if (errcheck == -1) {
                ::close(aFd);
            }
            connected = (aFd != -1);
        }
    }
    return aFd;
}

SocketActivo::~SocketActivo() {
}

SocketActivo::SocketActivo(const std::string &hostName, const std::string &service):
        SocketAmigo(-1){
    conectar(hostName, service);
}