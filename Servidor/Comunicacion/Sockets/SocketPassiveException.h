#ifndef _SOCKET_PASSIVE_EXCEPTION_H_
#define _SOCKET_PASSIVE_EXCEPTION_H_

#include <stdexcept>
#include "SocketException.h"

class SocketPassiveException: public SocketException {
public:
  explicit SocketPassiveException(std::string mensaje, std::string error, std::string archivo, int linea);
};


#endif