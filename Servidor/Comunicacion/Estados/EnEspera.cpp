
#include <iostream>
#include "EnEspera.h"
#include "../Sockets/SocketPeerException.h"
#include "../../PartidaLlenaExcepcion.h"

EnEspera::EnEspera(size_t cantMaxima, std::vector<ClienteProxy*>& clientes) :
    cantMaximaJugadores(cantMaxima),
    cantActualJugadores(0),
    clientes(clientes){
}

void EnEspera::sumarJugador(ClienteProxy *cliente) {
    std::unique_lock<std::mutex> lock(mutex);
    if (enJuego()){
        throw PartidaLlenaExcepcion("La partida se encuentra llena", __LINE__);
    }
    cantActualJugadores++;
    clientes.emplace_back(cliente);
    enviarCantidadDeJugadores();
    std::cout << "Cantidad actual de jugadores: " << cantActualJugadores << std::endl;
    if (enJuego()){
        estaLLena.notify_all();
    }
}

void EnEspera::ejecutar() {
    std::unique_lock<std::mutex> lock(mutex);
    while (!enJuego()){
        estaLLena.wait(lock);
    }

}

bool EnEspera::enJuego() {
    return cantActualJugadores == cantMaximaJugadores;
}

void EnEspera::enviarCantidadDeJugadores() {
    size_t i = 0;
    while (i < clientes.size()){
        try{
            clientes.at(i)->enviar(std::to_string(cantActualJugadores));
        }catch (SocketPeerException &e){
            sacarCliente(i);
            cantActualJugadores--;
            continue;
        }
        i++;
    }
}

void EnEspera::sacarCliente(size_t posicion){
    std::iter_swap(clientes.begin() + posicion, clientes.end()-1);
    //cierro el cliente, dado que asumo que murió.
    clientes.back()->desconectar();
    clientes.pop_back();
}

void EnEspera::cerrar() {
    cantActualJugadores = cantMaximaJugadores;
    estaLLena.notify_all();
}
