#include <chrono>
#include <thread>
#include "EnCarrera.h"
#include "../Utilidades.h"
#include "../Eventos/EventosParseables/FinSimulacion.h"

EnCarrera::EnCarrera(Pista &pista, HashProtegidoClientes &clientes):
    pista(pista), clientes(clientes), podio(1){ //CANTIDAD DE VUELTAS HARDCODEADA
    pista.inicializarPodio(&podio);
}

void EnCarrera::ejecutar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    std::vector<std::string> claves = clientes.obtenerClaves();
    for (auto& cliente : claves){
        clientes.obtener(cliente).ejecutarAccion();
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
