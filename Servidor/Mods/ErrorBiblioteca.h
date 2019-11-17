//
// Created by manfer on 17/11/19.
//

#ifndef SERVIDOR_ERRORBIBLIOTECA_H
#define SERVIDOR_ERRORBIBLIOTECA_H


#include <stdexcept>

class ErrorBiblioteca: public std::runtime_error {

public:
    ErrorBiblioteca(const std::string& msj);

    ErrorBiblioteca(const std::string& msj, const std::string& biblioteca,\
    char *error, int linea, const char *archivo);
};


#endif //SERVIDOR_ERRORBIBLIOTECA_H
