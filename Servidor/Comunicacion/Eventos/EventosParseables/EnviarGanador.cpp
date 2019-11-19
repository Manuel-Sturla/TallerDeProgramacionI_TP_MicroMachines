//
// Created by diego on 19/11/19.
//

#include "EnviarGanador.h"
#include "../../Utilidades.h"

EnviarGanador::EnviarGanador(Podio &podio) {
    std::vector<std::string> aux;
    aux.emplace_back("ganador");
    aux.emplace_back(podio.obtenerGanador());
    mensaje = unir(aux, SEPARADOR);
}

std::string EnviarGanador::obtenerParseado() {
    return mensaje;
}
