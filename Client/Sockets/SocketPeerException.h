#ifndef _COMMON_SOCKET_PEER_EXCEPTION_H_
#define _COMMON_SOCKET_PEER_EXCEPTION_H_

#include <stdexcept>
#include "SocketException.h"

class SocketPeerException: public SocketException {
public:
    explicit SocketPeerException(std::string mensaje, std::string error, std::string archivo, int linea);
};


#endif
