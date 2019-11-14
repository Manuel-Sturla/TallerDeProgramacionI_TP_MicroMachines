#include "EnviarExtra.h"
#include "../../Utilidades.h"

#define EVENTO_POS_EXTRA "posicionarExtra"

#define EVENTO_EXTRA_MURIO "eliminar"

EnviarExtra::EnviarExtra(std::unique_ptr<Modificador> &modificable) {
    std::vector<std::string> aux;
    if (modificable->esValido()){
        aux.emplace_back(EVENTO_POS_EXTRA);
        modificable->empaquetar(&aux);
    }else{
        aux.emplace_back(EVENTO_EXTRA_MURIO);
        modificable->empaquetarId(&aux);
    }
    parseado = unir(aux, SEPARADOR);
}

std::string EnviarExtra::obtenerParseado() {
    return parseado;
}
