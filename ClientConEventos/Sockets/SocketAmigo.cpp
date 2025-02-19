#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include "SocketAmigo.h"
#include "SocketPeerException.h"

SocketAmigo::SocketAmigo(int aFd) {
    fd = aFd;
}

SocketAmigo::SocketAmigo(SocketAmigo &&other) {
    this -> fd = other.fd;
    other.fd = -1;
}

SocketAmigo &SocketAmigo::operator=(SocketAmigo &&other) {
    if (this == &other) {
        return *this;
    }
    this -> fd = other.fd;
    other.fd = -1;
    return *this;
}

void SocketAmigo::enviar (std::string mensaje) {
    ssize_t lastSent;
    size_t sent = 0;
    size_t lenght = mensaje.length();
    while (sent < lenght) {
        lastSent = ::send(fd, &mensaje.c_str()[sent], lenght - sent, MSG_NOSIGNAL);
        if (lastSent == 0) {
            throw SocketPeerException("Comunicacion Perdida", strerror(errno), __FILE__, __LINE__);
        } else if (lastSent < 0) {
            throw SocketPeerException("Error al enviar: ", strerror(errno), __FILE__, __LINE__);
        }
        sent += lastSent;
    }
}

void SocketAmigo::recibir(std::string& answer, size_t lenght) {
    int newChars;
    std::vector<char> buffer(lenght);
    size_t recieved = 0;
    while (recieved < lenght) {
        newChars = recv(fd, &buffer[recieved], lenght - recieved, 0);
        if (newChars == 0) {
            throw SocketPeerException("Comunicacion terminada: ", strerror(errno), __FILE__, __LINE__);
        } else if (newChars < 0) {
            throw SocketPeerException("Error al recibir, conexion perdida: ", strerror(errno), __FILE__, __LINE__);
        }
        recieved += newChars;
    }
    answer.assign(buffer.data(), lenght);
}

void SocketAmigo::cerrar() {
    if (fd > 1){
        shutdown(fd, SHUT_RDWR);
        ::close(fd);
        fd = -1;
    }
}

SocketAmigo::~SocketAmigo() {
    if (fd > -1) {
        cerrar();
    }
}

void SocketAmigo::enviarLongitud(unsigned int longitud) {
    ssize_t lastSent;
    size_t sent = 0;
    size_t lenght = sizeof(unsigned int);
    while (sent < lenght) {
        lastSent = ::send(fd, &longitud, lenght - sent, MSG_NOSIGNAL);
        if (lastSent == 0) {
            throw SocketPeerException("Comunicacion Perdida", strerror(errno), __FILE__, __LINE__);
        } else if (lastSent < 0) {
            throw SocketPeerException("Error al enviar: ", strerror(errno), __FILE__, __LINE__);
        }
        sent += lastSent;
    }
}

unsigned int SocketAmigo::recibirLongitud() {
    int newChars;
    size_t recieved = 0;
    unsigned int longitud = 0;
    while (recieved < sizeof(unsigned int)) {
        newChars = recv(fd, &longitud, sizeof(unsigned int) - recieved, 0);
        if (newChars == 0) {
            throw SocketPeerException("Comunicacion terminada: ", strerror(errno), __FILE__, __LINE__);
        } else if (newChars < 0) {
            throw SocketPeerException("Error al recibir, conexion perdida: ", strerror(errno), __FILE__, __LINE__);
        }
        recieved += newChars;
    }
    return longitud;
}
