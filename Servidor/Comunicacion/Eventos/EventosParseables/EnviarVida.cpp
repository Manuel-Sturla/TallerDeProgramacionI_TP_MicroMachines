#include "EnviarVida.h"
#include "../../Utilidades.h"

#define EVENTO_VIDA "actualizarVida"

EnviarVida::EnviarVida(Carro &carro) {
    std::vector<std::string> mensaje;
    mensaje.emplace_back(EVENTO_VIDA);
    carro.empaquetarVida(&mensaje);
    parseado =  unir(mensaje, SEPARADOR);
}

std::string EnviarVida::obtenerParseado() {
    return parseado;
}
