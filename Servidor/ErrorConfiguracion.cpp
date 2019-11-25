//
// Created by manfer on 25/11/19.
//

#include "ErrorConfiguracion.h"

ErrorConfiguracion::ErrorConfiguracion(const std::string &msj, int linea, const char *archivo) :
    std::runtime_error(msj + "En " + std::string(archivo) + ":" + std::to_string(linea)){
}
