//
// Created by manfer on 25/11/19.
//

#ifndef SERVIDOR_ERRORCONFIGURACION_H
#define SERVIDOR_ERRORCONFIGURACION_H


#include <stdexcept>

class ErrorConfiguracion: public std::runtime_error {
public:
    ErrorConfiguracion(const std::string& msj, int linea, const char *archivo);
};


#endif //SERVIDOR_ERRORCONFIGURACION_H
