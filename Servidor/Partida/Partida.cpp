#include "Partida.h"
#include "../Comunicacion/Sockets/SocketPeerException.h"
#include "../PartidaLlenaExcepcion.h"
#include "../Comunicacion/Estados/EnCarrera.h"
#include "../Comunicacion/Estados/EnEspera.h"
#include "../Comunicacion/Eventos/EventosParseables/ComenzoLaPartida.h"
#include "../Comunicacion/Eventos/EventosParseables/EnviarMapa.h"


Partida::Partida(int cantJugadores, PlanoDePista *planoPista) :
estado(new EnEspera(cantJugadores, clientes)) {
    crearPista(planoPista);
    suelos.clear();
    pista.empaquetarSuelos(&suelos);
}

Partida::~Partida() {
}

void Partida::crearPista(PlanoDePista *planoDePista) {
    planoDePista -> crearPista(&pista);
}

std::vector<std::string> &Partida::obtenerMapa() {
    return suelos;
}

Carro *Partida::agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy &cliente) {
    EnEspera* estadoEnEspera = dynamic_cast<EnEspera *>(estado.get());
    estadoEnEspera->sumarJugador(cliente);
    return planoDeCarro -> crearCarro(&pista);
}

void Partida::run() {
    estado->ejecutar();
    enviarMensajesInicio();
    estado = std::unique_ptr<EstadoPartida> (new EnCarrera(pista, clientes));
    while(!clientes.estaVacio()) {
        try {
            estado->ejecutar();
        } catch (SocketPeerException &e) {
            clientes.estaVacio();
        }
    }
}


bool Partida::estaMuerto() {
    return clientes.estaVacio() && estado->enJuego();
}


void Partida::cerrar() {
    //Para asegurarme que no envíe nada a ningun cliente porque la quiero cerrar
    clientes.estaVacio();
    estado->cerrar();
}




void Partida::enviarMensajesInicio() {
    std::shared_ptr<EventosParseables> eventoComenzo (new ComenzoLaPartida());
    std::shared_ptr<EventosParseables> eventoEnviarMapa (new EnviarMapa(pista));
    for (auto& clave : clientes.obtenerClaves()){
        ClienteProxy& cliente = clientes.obtener(clave);
        cliente.encolarEvento(eventoComenzo);
        cliente.encolarEvento(eventoEnviarMapa);
        cliente.mandarAutoPropio();
    }
}

void Partida::eliminarCliente(ClienteProxy &cliente) {
    clientes.eliminar(std::to_string(cliente.obtenerID()));
}

bool Partida::estaEnJuego() {
    return estado->enJuego();
}

