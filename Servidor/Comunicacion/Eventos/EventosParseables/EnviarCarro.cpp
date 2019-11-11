#include "EnviarCarro.h"
#include "../../Utilidades.h"

#define EVENTO_POS_AUTO "posicionarAuto"

#define EVENTO_AUTO_MURIO "morir"

EnviarCarro::EnviarCarro(Carro &carro) {
    std::vector<std::string> aux;
    if (carro.esValido()){
        aux.emplace_back(EVENTO_POS_AUTO);
        carro.empaquetar(&aux);
    }else{
        aux.emplace_back(EVENTO_AUTO_MURIO);
        aux.emplace_back(carro.darIdConductor());
    }
    parseo = unir(aux, SEPARADOR);
}

std::string EnviarCarro::obtenerParseado() {
    return parseo;
}
