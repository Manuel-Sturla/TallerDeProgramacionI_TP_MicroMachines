//
// Created by manfer on 1/11/19.
//

#include "ElegirPartida.h"

ElegirPartida::ElegirPartida(Protocolo &protocolo, Servidor &servidor)
        : protocolo(protocolo), servidor(servidor) {

}

void ElegirPartida::ejecutar() {
    std::map<std::string, Partida>& partidas = servidor.obtenerPartidas();
    /*for(auto& partida : partidas){
        protocolo.enviar(partida.first); //Aca formatearia los datos de la partida
    }
    protocolo.enviar(MSJ_FIN);
    //Recibo el nombre de la partida a la cual el usuario quiere agregarse o crear
    std::string nombrePartida = protocolo.recibir();
    auto it = partidas.find(nombrePartida);
    if (it == partidas.end()){
        servidor.crearPartida();
    }
    partidas[nombrePartida].agregarJugador("nombre");
*/}
