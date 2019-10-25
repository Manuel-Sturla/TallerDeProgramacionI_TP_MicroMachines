#ifndef _SOCKET_ACTIVO_H_
#define _SOCKET_ACTIVO_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "SocketAmigo.h"

class SocketActivo: public SocketAmigo {
  private:
    static int conseguirConexion(struct addrinfo* ptr);

  public:
    SocketActivo();

    void conectar(const char* hostName, const char* service);

    ~SocketActivo();
};


#endif
