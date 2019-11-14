#include "SocketException.h"

SocketException::SocketException(const std::string &mensaje, std::string error, std::string archivo, int linea):
std::runtime_error(mensaje + error + ". En archivo: " + archivo +" ,linea: " + std::to_string(linea)){

}
