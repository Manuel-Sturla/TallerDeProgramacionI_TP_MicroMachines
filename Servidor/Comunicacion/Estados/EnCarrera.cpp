
#include "EnCarrera.h"
#include "../Comandos/Comando.h"

EnCarrera::EnCarrera(Pista &pista, std::vector<ClienteProxy *>& clientes):
    pista(pista), clientes(clientes){

}

void EnCarrera::ejecutar() {
    std::vector<ClienteProxy*>::iterator cliente;

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
    for (auto& extra : extras){
        proxy.enviar(extra); //parsearExtra(extra);
    }
    proxy.enviar(MSJ_FIN);
    for (auto& unAuto : autos){
        proxy.enviar(unAuto);
    }
    proxy.enviar(MSJ_FIN);
}