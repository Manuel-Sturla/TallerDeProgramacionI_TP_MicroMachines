#include <chrono>
#include <thread>
#include "EnCarrera.h"
#include "../Utilidades.h"

EnCarrera::EnCarrera(Pista &pista, std::vector<ClienteProxy *>& clientes):
    pista(pista), clientes(clientes){

}

void EnCarrera::ejecutar() {
    std::vector<ClienteProxy*>::iterator cliente;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    for (cliente = clientes.begin(); cliente != clientes.end(); cliente++) {
        (*cliente) -> ejecutarAccion();
    }
    pista.simular();
    actualizarEventos();
    for (cliente = clientes.begin(); cliente != clientes.end(); cliente++) {
        enviarPosicion(**cliente);
    }
}

void EnCarrera::actualizarEventos() {
    autos.clear();
    pista.empaquetarCarro(&autos);
}

bool EnCarrera::enJuego() {
    return true;
}

void EnCarrera::enviarPosicion(ClienteProxy &proxy) {
    proxy.enviar(unir(autos, SEPARADOR));
    proxy.enviar("finSimulacion");
    /*
    for (auto& extra : extras){
        proxy.enviar(extra); //parsearExtra(extra);
    }
    for (auto& unAuto : autos){
        proxy.enviar(unAuto);
    }*/
}