//
// Created by manfer on 5/11/19.
//

#include "HiloCliente.h"
#include "Sockets/SocketPeerException.h"

HiloCliente::HiloCliente(SocketAmigo& socketCliente, EnMenu &enMenu, EnJuego &enJuego):
    cliente(std::move(socketCliente)),
    menu(enMenu),
    juego(enJuego),
    estado(&menu),
    conectado(true),
    enviador(cliente, conectado) {
    enviador.start();
}

void HiloCliente::run() {
    try {
        while (conectado) {
            if (cliente.estaEnJuego()){
                estado = &juego;
            }
            estado->ejecutar(cliente);
        }
    }catch (SocketPeerException & e){
        conectado = false;
    }
}

void HiloCliente::desconectar() {
    cliente.desconectar();
    conectado = false;
    enviador.desconectar();
    enviador.join();
}

bool HiloCliente::estaMuerto() {
    return !conectado;
}
