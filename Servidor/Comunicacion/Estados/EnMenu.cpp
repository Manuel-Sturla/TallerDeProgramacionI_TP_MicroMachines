//
// Created by manfer on 5/11/19.
//

#include "EnMenu.h"
#include "../Sockets/SocketPeerException.h"
#include "../Eventos/CrearPartida.h"
#include "../Eventos/UnirAPartida.h"
#include "../Eventos/ObtenerPartidas.h"

#define MSJ_CMD_INVALIDO "ComandoInvalido"

EnMenu::EnMenu(HashProtegido &partidas, ConfiguracionServidor &config):
    partidas(partidas), mapasYAutos(config){
    //Creo comando CrearPartida y UnirseAPartida
    comandos.emplace("CrearPAR", new CrearPartida(partidas, mapasYAutos));
    comandos.emplace("PAR", new ObtenerPartidas(partidas));
    comandos.emplace("UnirPAR", new UnirAPartida(partidas, mapasYAutos));
    //ObtenerPartidas
    //ObtenerMapa
    //ObtenerAutos ?
}

void EnMenu::ejecutar(ClienteProxy &cliente) {
    std::string comando = cliente.recibir();
    if (comandos.find(comando) == comandos.end()){
        cliente.enviar(MSJ_CMD_INVALIDO);
    }else{
        comandos[comando]->ejecutar(cliente);
    }
}

