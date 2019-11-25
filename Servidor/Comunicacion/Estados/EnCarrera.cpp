#include <thread>
#include "EnCarrera.h"
#include "../Utilidades.h"
#include "../Eventos/EventosParseables/FinSimulacion.h"
#include "../Eventos/EventosParseables/EnviarPodio.h"
#include "../Eventos/EventosParseables/EnviarGanador.h"

EnCarrera::EnCarrera(Pista &pista, HashProtegidoClientes &clientes, int cantVueltas) :
    pista(pista), podio(cantVueltas),clientes(clientes) {
}

void EnCarrera::ejecutar() {
    clientes.ejecutarAccionesClientes();
    pista.simular();
    actualizarEventos();
    podio.actualizarPodio();

    std::vector<std::shared_ptr<EventoParseable>> eventoPodio;
    eventoPodio.emplace_back(new EnviarPodio(podio));
    clientes.enviarEventos(eventoPodio);

    if(podio.analizarVictoria()){
        std::vector<std::shared_ptr<EventoParseable>> eventoGanador;
        eventoGanador.emplace_back(new EnviarGanador(podio));
        clientes.enviarEventos(eventoGanador);
    }
    enviarPosiciones();
}

void EnCarrera::actualizarEventos() {
    eventos.clear();
    pista.empaquetarCarro(&eventos);
    pista.empaquetarExtras(&eventos);
}


void EnCarrera::enviarPosiciones() {
    std::shared_ptr<EventoParseable> eventoFinSimulacion (new FinSimulacion());
    eventos.emplace_back(eventoFinSimulacion);
    clientes.enviarEventos(eventos);
    eventos.clear();
}

void EnCarrera::inicializar() {
    pista.inicializarPodio(podio);
}

