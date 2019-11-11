
#include "EnviarAutoPropio.h"
#include "../../Utilidades.h"

#define EVENTO_MI_AUTO "posicionarAuto"

EnviarAutoPropio::EnviarAutoPropio(Carro *carro) : carro(carro){
}

std::string EnviarAutoPropio::obtenerParseado() {
    std::vector<std::string> mensaje;
    mensaje.emplace_back(EVENTO_MI_AUTO);
    mensaje.emplace_back("A0"); //hardcodeo un id
    carro->empaquetar(&mensaje);
    return unir(mensaje, SEPARADOR);
}
