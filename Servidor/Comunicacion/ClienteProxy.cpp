#include "ClienteProxy.h"
#include "Utilidades.h"
#include "Sockets/SocketPeerException.h"
#include "../Acciones/Acelerar.h"
#include "../Acciones/Frenar.h"
#include "../Acciones/GiroADerecha.h"
#include "../Acciones/GiroAIzquierda.h"
#include "EnMenu.h"
#include "EnJuego.h"

#define MSJ_CMD_INVALIDO "Comando invalido"
#define CMD_ACELERAR "acelerar"
#define CMD_FRENAR "frenar"
#define CMD_DERECHA "doblar derecha"
#define CMD_IZQUIERDA "doblar izquierda"
#define SALIR "salir"

ClienteProxy::ClienteProxy(SocketAmigo socketCliente) :
protocolo(std::move(socketCliente)){
}


ClienteProxy::~ClienteProxy() {
}

void ClienteProxy::desconectar() {
    protocolo.terminarConexion();
}
void ClienteProxy::ejecutarAccion() {
    if (!movimientos.empty()){
      miCarro->ejecutarAccion(movimientos.front().get());
      movimientos.pop();
    }
}


void ClienteProxy::enviar(const std::string &mensaje) {
    protocolo.enviar(mensaje);
}

std::string ClienteProxy::recibir() {
    return protocolo.recibir();
}
void ClienteProxy::encolarAccion(Accion* accion) {
    movimientos.push(std::unique_ptr<Accion> (accion));
}

void ClienteProxy::jugar() {
}

ClienteProxy::ClienteProxy(ClienteProxy&& otro): protocolo(std::move(otro.protocolo)){
    movimientos = std::move(otro.movimientos);
    miCarro = otro.miCarro;

    otro.miCarro = nullptr;
}
