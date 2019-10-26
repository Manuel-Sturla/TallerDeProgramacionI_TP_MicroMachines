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

    void unirse(const char *aService);

    void escuchar();

    SocketAmigo aceptarCliente();

    void cerrar();

    ~SocketPasivo();
};


#endif
