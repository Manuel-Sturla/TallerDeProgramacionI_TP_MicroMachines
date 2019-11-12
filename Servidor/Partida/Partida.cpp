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

Carro *Partida::agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy* cliente) {
    EnEspera* estadoEnEspera = dynamic_cast<EnEspera *>(estado.get());
    estadoEnEspera->sumarJugador(cliente);
    return planoDeCarro -> crearCarro(&pista);
}

void Partida::run() {
    estado->ejecutar();
    enviarMensajesInicio();
    estado = std::unique_ptr<EstadoPartida> (new EnCarrera(pista, clientes));
    while(!clientes.empty()) {
        try {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
            estado->ejecutar();
        } catch (SocketPeerException &e) {
            clientes.clear();
        }
    }
}


bool Partida::estaMuerto() {
    return clientes.empty() && estado->enJuego();
}


void Partida::cerrar() {
    //Para asegurarme que no envíe nada a ningun cliente porque la quiero cerrar
    clientes.clear();
    estado->cerrar();
}




void Partida::enviarMensajesInicio() {
    std::shared_ptr<EventoParseable> eventoComenzo (new ComenzoLaPartida());
    std::shared_ptr<EventoParseable> eventoEnviarMapa (new EnviarMapa(pista));
    for (auto& cliente : clientes){
        cliente->encolarEvento(eventoComenzo);
        cliente->encolarEvento(eventoEnviarMapa);
        cliente->mandarAutoPropio();
    }
}

