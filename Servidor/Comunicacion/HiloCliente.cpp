#include "HiloCliente.h"
#include "Sockets/SocketPeerException.h"

HiloCliente::HiloCliente(SocketAmigo &socketCliente, EnMenu &enMenu, EnJuego &enJuego, HashProtegido &partidas) :
    cliente(std::move(socketCliente)),
    menu(enMenu),
    juego(enJuego),
    estado(&menu),
    partidas(partidas),
    conectado(true),
    enviador(cliente, conectado) {
    enviador.start();
}

void HiloCliente::run() {
    try {
        while (conectado and !cliente.estaEnJuego()) {
            estado->ejecutar(cliente);
        }
        estado = &juego;
        while(conectado){
            estado->ejecutar(cliente);
        }
    }catch (SocketPeerException & e){
        conectado = false;
        if (cliente.estaEnJuego()){
            auto partida = partidas.obtener(cliente.obtenerPartida());
            partida->eliminarCliente(cliente);
            cliente.borrarAutoPropio();
        }
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
