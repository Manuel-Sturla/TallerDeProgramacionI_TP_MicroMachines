#include "SocketPasivo.h"
#include "SocketPassiveException.h"
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>

SocketPasivo::SocketPasivo() {
  fd = -1;
}
SocketPasivo::SocketPasivo(const std::string &servicio) :SocketPasivo(){
    unirseYEscuchar(servicio);
}

void SocketPasivo::unirse(const std::string &aService) {
  struct addrinfo hints;
  struct addrinfo *rst;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int errCheck = getaddrinfo(nullptr, aService.c_str(), &hints, &rst);
  if (errCheck != 0) {
      freeaddrinfo(rst);
      throw SocketPassiveException("Fallo en Bind: ", strerror(errno), __FILE__, __LINE__);
  }
  fd = getBind(rst);
  freeaddrinfo(rst);
}

int SocketPasivo::getBind(struct addrinfo *rst) {
  int aFd = -1;
  bool binded = false;
  struct addrinfo *ptr;
  for (ptr = rst; ptr != nullptr && !binded; ptr = ptr -> ai_next) {
    aFd = socket(ptr -> ai_family, ptr -> ai_socktype, ptr -> ai_protocol);
    if (aFd == -1) {
      throw SocketPassiveException("Error al obtener FD: ", strerror(errno), __FILE__, __LINE__);
    }
    int val = 1;
    int errCheck = setsockopt(aFd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (errCheck == -1) {
      ::close(aFd);
    }
    errCheck = ::bind(aFd, ptr -> ai_addr, ptr -> ai_addrlen);
    if (errCheck == -1) {
      ::close(aFd);
    }
    binded = (errCheck != -1);
  }
  return aFd;
}

void SocketPasivo::escuchar () {
  int errCheck = ::listen(fd, 1);
  if (errCheck == -1) {
    throw SocketPassiveException("Fallo en Listen: ", strerror(errno), __FILE__, __LINE__);
  }
}

SocketAmigo SocketPasivo::aceptarCliente() {
  int aFd = accept(fd, nullptr, nullptr);
  if (aFd == -1) {
    throw SocketPassiveException("Error en Accept: ", strerror(errno), __FILE__, __LINE__);
  }
  return std::move(SocketAmigo(aFd));
}

void SocketPasivo::cerrar() {
  shutdown(fd, SHUT_RDWR);
  ::close(fd);
  fd = -1;
}

SocketPasivo::~SocketPasivo() {
  if (fd != -1) {
    cerrar();
  }
}

void SocketPasivo::unirseYEscuchar(const std::string &servicio) {
    unirse(servicio);
    escuchar();
}


