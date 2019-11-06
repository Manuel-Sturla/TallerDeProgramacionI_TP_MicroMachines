//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_PARTIDALLENAEXCEPCION_H
#define SERVIDOR_PARTIDALLENAEXCEPCION_H

#include <stdexcept>

class PartidaLlenaExcepcion: public std::runtime_error {
public:
    PartidaLlenaExcepcion(const std::string &mensaje, int linea);

};

#endif //SERVIDOR_PARTIDALLENAEXCEPCION_H
