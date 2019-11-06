#include "Partida.h"
#include "../Comunicacion/Sockets/SocketPeerException.h"
#include "../PartidaLlenaExcepcion.h"
#include "../Comunicacion/Comandos/Comando.h"

Partida::Partida(int cantJugadores, PlanoDePista *pista) : continuar(true) {
    cantidadMaximaDeJugadores = cantJugadores;
    crearPista(pista);
}

Partida::~Partida() {
}

void Partida::crearPista(PlanoDePista *planoDePista) {
    planoDePista -> crearPista(&pista);
}

std::vector<std::string> &Partida::obtenerExtras() {
    return extras;
}

std::vector<std::string> &Partida::obtenerAutos() {
    return autos;
}

void Partida::simular() {
    pista.simular();
}

void Partida::actualizar() {
    autos.clear();
    suelos.clear();
    pista.empaquetarSuelos(&suelos);
    pista.empaquetarCarro(&autos);
}

std::vector<std::string> &Partida::obtenerMapa() {
    return suelos;
}

Carro *Partida::agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy* cliente) {
    if (pista.cantidadDeCarros() == cantidadMaximaDeJugadores) {
        throw PartidaLlenaExcepcion("La partida se encuentra llena", 40);
    }
    clientes.emplace_back(cliente);
    return planoDeCarro -> crearCarro(&pista);
}

void Partida::run() {
    std::vector<ClienteProxy*>::iterator cliente;
    while (continuar){
        try{
            for (cliente = clientes.begin(); cliente != clientes.end(); cliente++) {
                (*cliente) -> ejecutarAccion();
            }
            simular();
            actualizar();
            for (cliente = clientes.begin(); cliente != clientes.end(); cliente++) {
                enviarPosicion(**cliente);
            }
        }catch (SocketPeerException &e){
            continuar = false;
        }
    }
}

bool Partida::estaMuerto() {
    return continuar;
}

void Partida::enviarPosicion(ClienteProxy &proxy) {
    for (auto& extra : extras){
        proxy.enviar(extra); //parsearExtra(extra);
    }
    proxy.enviar(MSJ_FIN);
    for (auto& unAuto : autos){
        proxy.enviar(unAuto);
    }
    proxy.enviar(MSJ_FIN);
}

