#include "ClienteProxy.h"
#include "Utilidades.h"
#include "Comandos/ElegirPartida.h"
#include "Comandos/EnviarPosiciones.h"
#include "Comandos/EnviarMapa.h"
#include "Sockets/SocketPeerException.h"
#include "../Acciones/Acelerar.h"
#include "../Acciones/Frenar.h"
#include "../Acciones/GiroADerecha.h"
#include "../Acciones/GiroAIzquierda.h"

#define MSJ_CMD_INVALIDO "Comando invalido"
#define CMD_ACELERAR "acelerar"
#define CMD_FRENAR "frenar"
#define CMD_DERECHA "doblar derecha"
#define CMD_IZQUIERDA "doblar izquierda"

ClienteProxy::ClienteProxy(SocketAmigo socketCliente, Partida &partida) :
protocolo(std::move(socketCliente)), conectado(true){
    //Creo un hash de partidas hardcodeado, despues el cliente proxy recibirá el servidor con su hash
    std::map<std::string, std::string> partidas;
    partidas["Partida1"] = "Mira que loco";
    comandos.emplace("PAR", new ElegirPartida(protocolo, partidas));
    comandos.emplace("POS", new EnviarPosiciones(protocolo, partida.obtenerExtras(), partida.obtenerAutos()));
    comandos.emplace("MAP", new EnviarMapa(protocolo, partida.obtenerMapa()));
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

void ClienteProxy::recibirAccion() {
  std::string accion = protocolo.recibir();
    if (accion == CMD_ACELERAR){
      movimientos.push(std::unique_ptr<Accion>(new Acelerar()));
    }else if (accion == CMD_FRENAR){
      movimientos.push(std::unique_ptr<Accion>(new Frenar()));
    }else if (accion == CMD_DERECHA){
      movimientos.push(std::unique_ptr<Accion>(new GiroADerecha()));
    }else if (accion == CMD_IZQUIERDA){
      movimientos.push(std::unique_ptr<Accion>(new GiroAIzquierda()));
    }
}

void ClienteProxy::ejecutarAccion(Carro *autinio) {
    if (!movimientos.empty()){
      autinio->ejecutarAccion(movimientos.front().get());
      movimientos.pop();
    }
}
