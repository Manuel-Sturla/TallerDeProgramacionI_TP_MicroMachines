//
// Created by manfer on 10/11/19.
//

#include "EnviarMapa.h"
#include "../../Utilidades.h"

EnviarMapa::EnviarMapa(Pista &pista) :pista(pista) {
}

std::string EnviarMapa::obtenerParseado() {
    std::vector<std::string> mapa;
    //No agrega el nombre del evento al comienzo
    pista.empaquetarSuelos(&mapa);
    for ()
    return unir(mapa, SEPARADOR);
}
