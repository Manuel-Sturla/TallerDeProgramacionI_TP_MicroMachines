#include "EnviarAutoPropio.h"
#include "../../Utilidades.h"

#define EVENTO_MI_AUTO "posicionarAuto"

EnviarAutoPropio::EnviarAutoPropio(Carro &carro) {
    std::vector<std::string> mensaje;
    mensaje.emplace_back(EVENTO_MI_AUTO);
    carro.empaquetar(&mensaje);
    parseado =  unir(mensaje, SEPARADOR);
}

std::string EnviarAutoPropio::obtenerParseado() {
    return parseado;
}
