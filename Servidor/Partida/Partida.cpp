#include "Partida.h"
#include "../Comunicacion/Sockets/SocketPeerException.h"
#include "../PartidaLlenaExcepcion.h"
#include "../Comunicacion/Estados/EnCarrera.h"
#include "../Comunicacion/Estados/EnEspera.h"
#include "../Comunicacion/Eventos/EventosParseables/ComenzoLaPartida.h"
#include "../Comunicacion/Eventos/EventosParseables/EnviarMapa.h"


Partida::Partida(int cantJugadores, PlanoDePista *planoPista) :
continuar(true), estado(new EnEspera(cantJugadores, clientes)) {
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

Carro *Partida::agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy* cliente) {
    EnEspera* estadoEnEspera = dynamic_cast<EnEspera *>(estado.get());
    estadoEnEspera->sumarJugador(cliente);
    return planoDeCarro -> crearCarro(&pista);
}

void Partida::run() {
    estado->ejecutar();
    enviarMensajesInicio();
    estado = std::unique_ptr<EstadoPartida> (new EnCarrera(pista, clientes));
    while(continuar)
        try {
            estado->ejecutar();
        }catch (SocketPeerException &e){
            continuar = false;
    }
}


bool Partida::estaMuerto() {
    return !continuar;
}


void Partida::cerrar() {
    continuar = false;
    //Para asegurarme que no envíe nada a ningun cliente porque la quiero cerrar
    clientes.clear();
    if (!estado->enJuego()){
        EnEspera* estadoEnEspera = dynamic_cast<EnEspera *>(estado.get());
        estadoEnEspera->cerrar();
    }
}




void Partida::enviarMensajesInicio() {
    std::shared_ptr<EventosParseables> eventoComenzo (new ComenzoLaPartida());
    std::shared_ptr<EventosParseables> eventoEnviarMapa (new EnviarMapa(pista));
    for (auto& cliente : clientes){
        cliente->encolarEvento(eventoComenzo);
        cliente->encolarEvento(eventoEnviarMapa);
        cliente->mandarAutoPropio();
    }
}

