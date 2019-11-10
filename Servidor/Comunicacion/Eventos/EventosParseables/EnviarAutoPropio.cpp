
#include "EnviarAutoPropio.h"
#include "../../Utilidades.h"

#define EVENTO_MI_AUTO "AutoPropio"

EnviarAutoPropio::EnviarAutoPropio(Carro *carro) : carro(carro){
}

std::string EnviarAutoPropio::obtenerParseado() {
    std::vector<std::string> mensaje;
    mensaje.emplace_back(EVENTO_MI_AUTO);
    carro->empaquetar(&mensaje);
    return unir(mensaje, SEPARADOR);
}
