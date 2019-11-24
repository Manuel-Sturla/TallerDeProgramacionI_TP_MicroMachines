#include "Partida.h"
#include "../Comunicacion/Sockets/SocketPeerException.h"
#include "../PartidaLlenaExcepcion.h"
#include "../Comunicacion/Estados/EnCarrera.h"
#include "../Comunicacion/Estados/EnEspera.h"
#include "../Comunicacion/Eventos/EventosParseables/ComenzoLaPartida.h"
#include "../Comunicacion/Eventos/EventosParseables/EnviarMapa.h"
#include "../Comunicacion/Eventos/EventosParseables/EliminarCarro.h"
#include "../Mods/ModAuto.h"


Partida::Partida(int cantJugadores, PlanoDePista *planoPista) :
    estadoEnEspera(cantJugadores, clientes),
    estadoEnCarrera(pista, clientes),
    enJuego(false){
    crearPista(planoPista);
suelos.clear();
    pista.empaquetarSuelos(&suelos);
    //mods.emplace_back(new ModAuto("../Mods/Implementaciones/ModBoost/Lib/libBoost.so"));
}

Partida::~Partida() {
}

void Partida::crearPista(PlanoDePista *planoDePista) {
    planoDePista -> crearPista(pista);
}

std::vector<std::string> &Partida::obtenerMapa() {
    return suelos;
}

void Partida::agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy &cliente) {
    std::unique_lock<std::mutex> lock(mutex);
    estadoEnEspera.sumarJugador(cliente, pista,  planoDeCarro);
    if (estadoEnEspera.enJuego()){
        estaLlena.notify_all();
    }
}

void Partida::run() {
    std::unique_lock<std::mutex> lock(mutex);
    while(!estadoEnEspera.enJuego()){
        estaLlena.wait(lock);
    }
    enviarMensajesInicio();
    estadoEnCarrera.inicializar();
    enJuego = true;
    while(!clientes.estaVacio()) {
        try {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
            llamarMods();
            estadoEnCarrera.ejecutar();
        } catch (SocketPeerException &e) {

        }
    }
}


bool Partida::estaMuerto() {
    return clientes.estaVacio() && enJuego;
}


void Partida::cerrar() {
    //Para asegurarme que no envíe nada a ningun cliente porque la quiero cerrar
    clientes.eliminarTodos();
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
    return enJuego;
}

void Partida::llamarMods() {
    for (auto& mod : mods){
        mod->activar(pista.obtenerCarros());
    }
}

