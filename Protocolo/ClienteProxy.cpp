//
// Created by manfer on 31/10/19.
//

#include <sstream>
#include "ClienteProxy.h"
#include "Utilidades.h"
#include "Comandos/ElegirPartida.h"
#include "Comandos/EnviarPosiciones.h"
#include "Comandos/EnviarMapa.h"

#define SEPARADOR ';'

ClienteProxy::ClienteProxy(SocketAmigo socketCliente, Partida &partida) : protocolo(std::move(socketCliente)){
    //Creo un hash de partidas hardcodeado, despues el cliente proxy recibirá el servidor con su hash
    std::map<std::string, std::string> partidas;
    partidas["Partida1"] = "Mira que loco";
    comandos.emplace("PAR", new ElegirPartida(protocolo, partidas));
    comandos.emplace("POS", new EnviarPosiciones(protocolo, partida.obtenerExtras(), partida.obtenerAutos()));
    comandos.emplace("MAP", new EnviarMapa(protocolo));
}

std::string ClienteProxy::obtenerComando() {
    return protocolo.recibir();
}

void ClienteProxy::ejecutarComando() {
    std::string comando = protocolo.recibir();
    comandos[comando]->ejecutar();
}
