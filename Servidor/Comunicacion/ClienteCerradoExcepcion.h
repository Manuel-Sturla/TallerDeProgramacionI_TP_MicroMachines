//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_CLIENTECERRADOEXCEPCION_H
#define SERVIDOR_CLIENTECERRADOEXCEPCION_H


#include <stdexcept>

class ClienteCerradoExcepcion: public std::runtime_error {
public:
    ClienteCerradoExcepcion();
};


#endif //SERVIDOR_CLIENTECERRADOEXCEPCION_H
