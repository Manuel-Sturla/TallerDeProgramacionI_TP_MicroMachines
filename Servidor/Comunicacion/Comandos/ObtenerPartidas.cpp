//
// Created by diego on 7/11/19.
//

#include "ObtenerPartidas.h"
#include "../../Partida/HashProtegido.h"

ObtenerPartidas::ObtenerPartidas(HashProtegido &partidas) :\
partidas(partidas) {}

void ObtenerPartidas::ejecutar(ClienteProxy &cliente) {
    for(auto& partida : partidas.obtenerClaves()){
        cliente.enviar(partida);
    }
    cliente.enviar(MSJ_FIN);
}
