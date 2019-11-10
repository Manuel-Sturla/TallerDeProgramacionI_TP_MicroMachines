//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_EXCEPCIONCONPOS_H
#define OPENGLTEST_EXCEPCIONCONPOS_H


#include <stdexcept>

class ExcepcionConPos : public std::runtime_error {
private:
    static std::string crearMensaje(const char* archivo, int linea, std::string& mensaje){
        std::string falla("Error: " + mensaje);
        falla.append(" en el archivo: ");
        falla.append(archivo);
        falla.append(" en la linea: ");
        falla.append(std::to_string(linea));
        return falla;
    }

public:
    ExcepcionConPos(const char* archivo, int linea, std::string mensaje) : std::runtime_error(crearMensaje(archivo, linea, mensaje)) {}
};


#endif //OPENGLTEST_EXCEPCIONCONPOS_H
