//
// Created by manfer on 31/10/19.
//

#include <sstream>
#include "ClienteProxy.h"
#include "Utilidades.h"
#include "Comandos/ElegirPartida.h"
#include "Comandos/EnviarPosiciones.h"
#include "Comandos/EnviarMapa.h"
#include "Comandos/AgregarMovimiento.h"
#include "SocketPeerException.h"

#define MSJ_CMD_INVALIDO "Comando invalido"

ClienteProxy::ClienteProxy(SocketAmigo socketCliente, Partida &partida) :
protocolo(std::move(socketCliente)), conectado(true){
    //Creo un hash de partidas hardcodeado, despues el cliente proxy recibirá el servidor con su hash
    std::map<std::string, std::string> partidas;
    partidas["Partida1"] = "Mira que loco";
    comandos.emplace("PAR", new ElegirPartida(protocolo, partidas));
    comandos.emplace("POS", new EnviarPosiciones(protocolo, partida.obtenerExtras(), partida.obtenerAutos()));
    comandos.emplace("MAP", new EnviarMapa(protocolo, partida.obtenerMapa()));
    //comandos.emplace("MOV", new AgregarMovimiento(protocolo));

}


void ClienteProxy::ejecutarComando() {
    try{
        std::string comando = protocolo.recibir();
        if (comandos.find(comando) == comandos.end()){
            protocolo.enviar(MSJ_CMD_INVALIDO);
        }else{
            comandos[comando]->ejecutar();
        }
    } catch(SocketPeerException &e){
        conectado = false;
    }
}

ClienteProxy::~ClienteProxy() {
    for (auto it = comandos.begin(); it != comandos.end(); it++){
        it->second.reset();
    }
}

bool ClienteProxy::estaConectado() {
    return conectado;
}

void ClienteProxy::desconectar() {
    protocolo.terminarConexion();
}
