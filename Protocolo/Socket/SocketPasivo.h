#ifndef _SOCKET_PASSIVE_H_
#define _SOCKET_PASSIVE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "SocketAmigo.h"

class SocketPasivo {
  private:
    int fd;

    int getBind(struct addrinfo* ptr);
  public:
    SocketPasivo();
    SocketPasivo(const std::string& servicio);

    void unirse(const std::string &aService);

    void escuchar();

    void unirseYEscuchar(const std::string& servicio);

    SocketAmigo aceptarCliente();

    void cerrar();

    ~SocketPasivo();
};


#endif
