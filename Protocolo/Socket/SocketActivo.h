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
    SocketActivo(const std::string &hostName, const std::string &service);

    void conectar(const std::string &hostName, const std::string &service);

    ~SocketActivo();
};


#endif
