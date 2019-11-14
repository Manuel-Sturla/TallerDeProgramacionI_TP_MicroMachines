#include "EnviarPodio.h"
#include "../../Utilidades.h"

EnviarPodio::EnviarPodio(Podio &podio) {
    std::vector<std::string> aux;
    aux.emplace_back("podio");
    aux.emplace_back(podio.obtenerGanador());
    mensaje = unir(aux, SEPARADOR);
}

std::string EnviarPodio::obtenerParseado() {
    return mensaje;
}
