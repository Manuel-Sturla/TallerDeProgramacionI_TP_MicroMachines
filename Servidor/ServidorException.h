//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_SERVIDOREXCEPTION_H
#define SERVIDOR_SERVIDOREXCEPTION_H


#include <stdexcept>

class ServidorException: public std::runtime_error {

public:
    ServidorException(const std::string &mensaje, int linea, const std::string &archivo);
};


#endif //SERVIDOR_SERVIDOREXCEPTION_H
