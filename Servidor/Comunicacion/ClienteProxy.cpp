#include "ClienteProxy.h"
#include "../Acciones/Acelerar.h"
#include "Eventos/EventosParseables/EnviarAutoPropio.h"
#include "ClienteCerradoExcepcion.h"

#define MSJ_CMD_INVALIDO "Comando invalido"
#define CMD_ACELERAR "acelerar"
#define CMD_FRENAR "frenar"
#define CMD_DERECHA "doblar derecha"
#define CMD_IZQUIERDA "doblar izquierda"
#define SALIR "salir"

ClienteProxy::ClienteProxy(SocketAmigo socketCliente) :
        protocolo(std::move(socketCliente)), enJuego(false){
}


ClienteProxy::~ClienteProxy() {
}

void ClienteProxy::desconectar() {
    eventosAEnviar.encolar(nullptr);
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
    enJuego = true;
}

ClienteProxy::ClienteProxy(ClienteProxy&& otro): protocolo(std::move(otro.protocolo)){
    movimientos = std::move(otro.movimientos);
    miCarro = otro.miCarro;

    otro.miCarro = nullptr;
}

bool ClienteProxy::estaEnJuego() {
    return enJuego;
}

void ClienteProxy::setCarro(Carro* carro) {
    miCarro = carro;
}

void ClienteProxy::enviarEvento() {
    auto evento = eventosAEnviar.desencolar();
    if (evento.get() == nullptr){
        throw ClienteCerradoExcepcion();
    }
    std::string eventoParseado = evento->obtenerParseado();
    enviar(eventoParseado);
}

void ClienteProxy::encolarEvento(EventoParseable *evento) {
    eventosAEnviar.encolar(evento);
}

void ClienteProxy::encolarEvento(std::shared_ptr<EventoParseable>& evento) {
    eventosAEnviar.encolar(evento);
}

void ClienteProxy::mandarAutoPropio() {
    eventosAEnviar.encolar(new EnviarAutoPropio(miCarro));
}
