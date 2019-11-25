//
// Created by manfer on 25/11/19.
//

#include "EnviarPistas.h"
#include "../../Utilidades.h"

EnviarPistas::EnviarPistas(std::vector<std::string>& pistasRecibidas) : pistas(pistasRecibidas){
}

std::string EnviarPistas::obtenerParseado() {
    return unir(pistas, SEPARADOR);
}
