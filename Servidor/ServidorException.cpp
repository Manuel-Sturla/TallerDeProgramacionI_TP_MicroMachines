//
// Created by manfer on 5/11/19.
//

#include "ServidorException.h"

ServidorException::ServidorException(const std::string &mensaje, int linea, const std::string &archivo) :
runtime_error(mensaje + ". En: " + std::to_string(linea) +":"+ archivo){
}
