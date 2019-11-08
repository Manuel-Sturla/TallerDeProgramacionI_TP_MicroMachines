//
// Created by diego on 7/11/19.
//

#include "ObtenerPartidas.h"

ObtenerPartidas::ObtenerPartidas(std::map<std::string, std::shared_ptr<Partida>> &partidas) :\
partidas(partidas) {}

void ObtenerPartidas::ejecutar(ClienteProxy &cliente) {
    for(auto& partida : partidas){
        cliente.enviar(partida.first);
    }
    cliente.enviar(MSJ_FIN);
}
