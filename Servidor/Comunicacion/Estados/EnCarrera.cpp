#include <chrono>
#include <thread>
#include "EnCarrera.h"
#include "../Utilidades.h"
#include "../Eventos/EventosParseables/FinSimulacion.h"

EnCarrera::EnCarrera(Pista &pista, std::vector<ClienteProxy *>& clientes):
    pista(pista), clientes(clientes), podio(1){ //CANTIDAD DE VUELTAS HARDCODEADA
    pista.inicializarPodio(&podio);
}

void EnCarrera::ejecutar() {
    std::vector<ClienteProxy*>::iterator cliente;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    for (cliente = clientes.begin(); cliente != clientes.end(); cliente++) {
        (*cliente) -> ejecutarAccion();
    }
    pista.simular();
    actualizarEventos();
    podio.actualizarPodio();
    podio.analizarVictoria();
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
    std::shared_ptr<EventosParseables> eventoFinSimulacion (new FinSimulacion());
    for (auto& cliente : clientes){
        for (auto& evento : eventos){
            cliente->encolarEvento(evento);
        }
        cliente->encolarEvento(eventoFinSimulacion);
    }
}

void EnCarrera::cerrar() {

}
