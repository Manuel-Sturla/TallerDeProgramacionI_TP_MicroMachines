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
#define SALIR "salir"

ClienteProxy::ClienteProxy(SocketAmigo socketCliente, Servidor &servidor, Carro *unCarro) :
protocolo(std::move(socketCliente)), conectado(true){
    //Creo un hash de partidas hardcodeado, despues el cliente proxy recibirá el servidor con su hash
    comandos.emplace("PAR", new ElegirPartida(protocolo, servidor));
    //comandos.emplace("POS", new EnviarPosiciones(protocolo, servidor.obtenerPartidas()["prueba"].obtenerExtras(), servidor.obtenerPartidas()["prueba"].obtenerAutos()));
    //comandos.emplace("MAP", neS", new EnviarPosiciones(protocolo, servidor.obtenerPartidas()["prueba"].obtenerExtras(), servidor.obtenerPartidas()["prueba"].obtenerAutos()));
    miCarro = unCarro;
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
    }else if (accion == SALIR){
        conectado = false;
    }
}

void ClienteProxy::ejecutarAccion() {
    if (!movimientos.empty()){
      miCarro->ejecutarAccion(movimientos.front().get());
      movimientos.pop();
    }
}

void ClienteProxy::enviarPosiciones() {
    comandos["POS"]->ejecutar();
}

void ClienteProxy::run() {
    try{
        while (estaConectado()){
            recibirAccion();
        }
    }catch (SocketPeerException &e){
        conectado = false;
    }
}

void ClienteProxy::unirseAPartida() {
    comandos["PAR"]->ejecutar();
}

bool ClienteProxy::estaMuerto() {
    return conectado;
}
