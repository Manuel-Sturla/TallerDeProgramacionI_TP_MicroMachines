//
// Created by diego on 7/11/19.
//

#include "ObtenerPartidas.h"
#include "../../Partida/HashProtegido.h"
#include "EnviarPartidas.h"

ObtenerPartidas::ObtenerPartidas(HashProtegido &partidas) :\
partidas(partidas) {}

void ObtenerPartidas::ejecutar(ClienteProxy &cliente) {
    cliente.encolarEvento(new EnviarPartidas(partidas));
}

