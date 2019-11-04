//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_SOCKETEXCEPTION_H
#define PROTOCOLO_SOCKETEXCEPTION_H


#include <stdexcept>

class SocketException: public std::runtime_error {
public:
    SocketException(const std::string &mensaje, std::string error, std::string archivo, int linea);
};


#endif //PROTOCOLO_SOCKETEXCEPTION_H
