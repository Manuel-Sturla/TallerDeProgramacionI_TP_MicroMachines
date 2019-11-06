//
// Created by manfer on 5/11/19.
//

#include "HiloCliente.h"
#include "Sockets/SocketPeerException.h"

HiloCliente::HiloCliente(SocketAmigo& cliente, EnMenu &enMenu, EnJuego &enJuego):
    cliente(std::move(cliente)), menu(enMenu), juego(enJuego),estado(&juego), conectado(true){

}

void HiloCliente::run() {
    try {
        while (conectado) {
            estado->ejecutar(cliente);
        }}
    catch (SocketPeerException & e){
        desconectar();
    }
}

void HiloCliente::desconectar() {
    cliente.desconectar();
    conectado = false;
}

bool HiloCliente::estaMuerto() {
    return !conectado;
}
