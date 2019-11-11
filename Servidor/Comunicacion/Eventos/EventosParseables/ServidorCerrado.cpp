#include "ServidorCerrado.h"

ServidorCerrado::ServidorCerrado() {
    mensaje = "BYE";
}

std::string ServidorCerrado::obtenerParseado() {
    return mensaje;
}

