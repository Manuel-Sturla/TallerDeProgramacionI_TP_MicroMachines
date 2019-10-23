//
// Created by manfer on 22/10/19.
//

#ifndef BIBLIOTECASLOCAS_ERRORBIBLIOTECA_H
#define BIBLIOTECASLOCAS_ERRORBIBLIOTECA_H


#include <stdexcept>

class ErrorBiblioteca: public std::runtime_error {

public:
    ErrorBiblioteca(std::string msj);

    ErrorBiblioteca(const std::string msj, const std::string biblioteca,\
    char *error, int linea, const char *archivo);
};


#endif //BIBLIOTECASLOCAS_ERRORBIBLIOTECA_H
