#include <iostream>
#include "EnEspera.h"
#include "../Sockets/SocketPeerException.h"
#include "../../PartidaLlenaExcepcion.h"
#include "../../Partida/Pista.h"
#include "../../Planos/PlanoDeCarro.h"
#include "../Eventos/EventosParseables/EnviarCantJugadores.h"

EnEspera::EnEspera(size_t cantMaxima, HashProtegidoClientes &clientes) :
    cantMaximaJugadores(cantMaxima),
    cantActualJugadores(0),
    clientes(clientes){
}

void EnEspera::sumarJugador(ClienteProxy &cliente, Pista &pista,
                            PlanoDeCarro *planoCarro) {
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
    cliente.setCarro(planoCarro->crearCarro(pista, cliente.obtenerID()));
    enviarCantidadDeJugadores();
}


bool EnEspera::enJuego() {
    return cantActualJugadores == cantMaximaJugadores;
}

void EnEspera::enviarCantidadDeJugadores() {
    std::vector<std::shared_ptr<EventoParseable>> aux;
    aux.emplace_back(new EnviarCantJugadores(cantActualJugadores));
    clientes.enviarEventos(aux);
}

void EnEspera::cerrar() {
    cantActualJugadores = cantMaximaJugadores;
}

void EnEspera::eliminarCliente() {
    cantActualJugadores--;
}




