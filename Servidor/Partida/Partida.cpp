#include "Partida.h"
#include "../Comunicacion/Sockets/SocketPeerException.h"
#include "../PartidaLlenaExcepcion.h"
#include "../Comunicacion/Estados/EnCarrera.h"
#include "../Comunicacion/Estados/EnEspera.h"
#include "../Comunicacion/Eventos/EventosParseables/ComenzoLaPartida.h"
#include "../Comunicacion/Eventos/EventosParseables/EnviarMapa.h"
#include "../Comunicacion/Eventos/EventosParseables/EliminarCarro.h"


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
    //Aca hay / habia una race condition porque la partida comienza antes de que se devuelva el auto
    estadoEnEspera->sumarJugador(cliente, pista,  planoDeCarro);
}

void Partida::run() {
    estado->ejecutar();
    enviarMensajesInicio();
    estado = std::unique_ptr<EstadoPartida> (new EnCarrera(pista, clientes));
    while(!clientes.estaVacio()) {
        try {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
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
    std::shared_ptr<EventoParseable> eventoComenzo (new ComenzoLaPartida());
    std::shared_ptr<EventoParseable> eventoEnviarMapa (new EnviarMapa(pista));
    for (auto& clave : clientes.obtenerClaves()){
        ClienteProxy& cliente = clientes.obtener(clave);
        cliente.encolarEvento(eventoComenzo);
        cliente.encolarEvento(eventoEnviarMapa);
        cliente.mandarAutoPropio();
    }
}

void Partida::eliminarCliente(ClienteProxy &cliente) {
    clientes.eliminar(std::to_string(cliente.obtenerID()));
    std::shared_ptr<EventoParseable> eventoEliminarCarro (new EliminarCarro(cliente.obtenerID()));
    for (auto& clave : clientes.obtenerClaves()){
        ClienteProxy& cliente = clientes.obtener(clave);
        cliente.encolarEvento(eventoEliminarCarro);
    }
}

bool Partida::estaEnJuego() {
    return estado->enJuego();
}

