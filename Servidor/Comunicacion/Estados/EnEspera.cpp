
#include <iostream>
#include "EnEspera.h"
#include "../Sockets/SocketPeerException.h"

EnEspera::EnEspera(size_t cantMaxima, std::vector<ClienteProxy*>& clientes) :
    cantMaximaJugadores(cantMaxima),
    cantActualJugadores(0),
    clientes(clientes){
}

void EnEspera::sumarJugador() {
    std::unique_lock<std::mutex> lock(mutex);
    cantActualJugadores++;
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
            cerrarCliente(i);
            cantActualJugadores--;
            continue;
        }
        i++;
    }
}

void EnEspera::cerrarCliente(size_t posicion){
    std::iter_swap(clientes.begin() + posicion, clientes.end()-1);
    //cierro el cliente, dado que asumo que murió.
    clientes.back()->desconectar();
    clientes.pop_back();
}

void EnEspera::cerrar() {
    cantActualJugadores = cantMaximaJugadores;
    estaLLena.notify_all();
}
