//
// Created by manfer on 22/10/19.
//

#ifndef BIBLIOTECASLOCAS_ERRORLIBRERIA_H
#define BIBLIOTECASLOCAS_ERRORLIBRERIA_H


#include <stdexcept>

class ErrorLibreria: public std::runtime_error {

public:
    ErrorLibreria(std::string msj);
};


#endif //BIBLIOTECASLOCAS_ERRORLIBRERIA_H
