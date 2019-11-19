#include <thread>
#include "EnCarrera.h"
#include "../Utilidades.h"
#include "../Eventos/EventosParseables/FinSimulacion.h"
#include "../Eventos/EventosParseables/EnviarPodio.h"
#include "../Eventos/EventosParseables/EnviarGanador.h"

EnCarrera::EnCarrera(Pista &pista, HashProtegidoClientes &clientes):
    pista(pista), clientes(clientes), podio(1){ //CANTIDAD DE VUELTAS HARDCODEADA
    pista.inicializarPodio(podio);
}

void EnCarrera::ejecutar() {
    std::vector<std::string> claves = clientes.obtenerClaves();
    for (auto& cliente : claves){
        clientes.obtener(cliente).ejecutarAccion();
    }
    pista.simular();
    actualizarEventos();
    podio.actualizarPodio();
    std::shared_ptr<EventoParseable> eventoPodio (new EnviarPodio(podio));
    for (auto& cliente : clientes.obtenerClaves()){
        clientes.obtener(cliente).encolarEvento(eventoPodio);
    }
    if(podio.analizarVictoria()){
        std::shared_ptr<EventoParseable> eventoGanador (new EnviarGanador(podio));
        for (auto& cliente : clientes.obtenerClaves()){
            clientes.obtener(cliente).encolarEvento(eventoGanador);
        }
    }
    enviarPosiciones();
}

void EnCarrera::actualizarEventos() {
    eventos.clear();
    pista.empaquetarCarro(&eventos);
    pista.empaquetarExtras(&eventos);
}

bool EnCarrera::enJuego() {
    return true;
}

void EnCarrera::enviarPosiciones() {
    std::shared_ptr<EventoParseable> eventoFinSimulacion (new FinSimulacion());
    for (auto& cliente : clientes.obtenerClaves()){
        for (auto& evento : eventos){
            clientes.obtener(cliente).encolarEvento(evento);
        }
        clientes.obtener(cliente).encolarEvento(eventoFinSimulacion);
    }
}

void EnCarrera::cerrar() {
}
