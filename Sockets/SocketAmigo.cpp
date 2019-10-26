#include <sys/socket.h>
#include <unistd.h>
#include "SocketAmigo.h"
#include "common_SocketPeerException.h"

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
  int operationState;
  std::string::iterator iterator =  mensaje.begin();
  char currentChar = *iterator;
  while (iterator != mensaje.end()) {
    operationState = ::send(fd, (void*) &currentChar, 1, MSG_NOSIGNAL);
    if (operationState == 0) {
      throw common_SocketPeerException("Comunicacion Perdida");
    } else if (operationState == -1) {
      throw common_SocketPeerException("SOCKET CERRADO FORZOZAMENTE");
    }
    iterator ++;
    currentChar = *iterator;
  }
}

void SocketAmigo::recibir(std::string *answer) {
  int operationState;
  char currentChar = ' ';
  while (currentChar != '\n') {
    operationState = recv(fd, &currentChar, 1, 0);
    if (operationState == 0) {
      throw common_SocketPeerException("Comunicacion Perdida");
    } else if (operationState == -1) {
      throw common_SocketPeerException("SOCKET CERRADO ABRUPTAMENTE");
    }
    *answer += currentChar;
  }
}

void SocketAmigo::cerrar() {
  shutdown(fd, SHUT_RDWR);
  ::close(fd);
  fd = -1;
}

SocketAmigo::~SocketAmigo() {
  if (fd != -1) {
    close();
  }
}
