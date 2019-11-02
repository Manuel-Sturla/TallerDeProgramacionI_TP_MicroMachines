#include "SocketPassiveException.h"

SocketPassiveException::SocketPassiveException(std::string mensaje, std::string error, std::string archivo, int linea) :
SocketException(mensaje, error, archivo, linea){

}
