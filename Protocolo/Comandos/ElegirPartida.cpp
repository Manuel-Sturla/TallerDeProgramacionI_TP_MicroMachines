//
// Created by manfer on 1/11/19.
//

#include "ElegirPartida.h"

ElegirPartida::ElegirPartida(Protocolo &protocolo, std::map<std::string, std::string> &partidas)
        : protocolo(protocolo), partidas(partidas) {

}

void ElegirPartida::ejecutar() {
    for(auto& partida : partidas){
        protocolo.enviar(partida.second); //Aca formatearia los datos de la partida
    }
    protocolo.enviar(MSJ_FIN);
    //Recibo el nombre de la partida a la cual el usuario quiere agregarse o crear
    std::string nombrePartida = protocolo.recibir();
    auto it = partidas.find(nombrePartida);
    if (it == partidas.end()){
        partidas.emplace(nombrePartida, "CREO PARTIDA NUEVA");
    }
    //partidas[nombrePartida].agregarJugador("nombre");
}
