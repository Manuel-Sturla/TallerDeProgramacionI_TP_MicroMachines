#include <iostream>
#include "EnEspera.h"
#include "../Sockets/SocketPeerException.h"
#include "../../PartidaLlenaExcepcion.h"
#include "../../Partida/Pista.h"
#include "../../Planos/PlanoDeCarro.h"

EnEspera::EnEspera(size_t cantMaxima, HashProtegidoClientes &clientes) :
    cantMaximaJugadores(cantMaxima),
    cantActualJugadores(0),
    clientes(clientes){
}

void EnEspera::sumarJugador(ClienteProxy &cliente, Pista &pista,
                            PlanoDeCarro *planoCarro) {
    std::unique_lock<std::mutex> lock(mutex);
    if (enJuego()){
        throw PartidaLlenaExcepcion("La partida se encuentra llena", __LINE__);
    }
    cantActualJugadores++;
    contadorId ++;
    if (!clientes.ubicar(std::to_string(contadorId), cliente)){
        //Si no se lo pudo ubicar es porque ya hay un jugador con ese Id (no deberia pasar)
        return;
    }
    cliente.setID(contadorId);
    cliente.setCarro(planoCarro->crearCarro(&pista, cliente.obtenerID()));
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
    std::vector<std::string> claves = clientes.obtenerClaves();
    for (auto& clave : claves){
        try{
            clientes.obtener(clave).enviar(std::to_string(cantActualJugadores));
        }catch (SocketPeerException &e){
            clientes.obtener(clave).desconectar();
            clientes.eliminar(clave);
            cantActualJugadores--;
        }
    }
}

void EnEspera::cerrar() {
    cantActualJugadores = cantMaximaJugadores;
    estaLLena.notify_all();
}
