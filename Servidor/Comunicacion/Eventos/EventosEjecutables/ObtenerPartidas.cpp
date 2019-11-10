//
// Created by diego on 7/11/19.
//

#include "ObtenerPartidas.h"
#include "../../../Partida/HashProtegido.h"
#include "../EventosParseables/EnviarPartidas.h"

ObtenerPartidas::ObtenerPartidas(HashProtegido &partidas) :\
partidas(partidas) {}

void ObtenerPartidas::ejecutar(ClienteProxy &cliente, std::vector<std::string> argumento) {
    cliente.encolarEvento(new EnviarPartidas(partidas));
}

