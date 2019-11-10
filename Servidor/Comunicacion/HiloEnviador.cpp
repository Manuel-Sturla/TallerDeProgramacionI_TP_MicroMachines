#include "HiloEnviador.h"
#include "ClienteProxy.h"
#include "Sockets/SocketPeerException.h"

HiloEnviador::HiloEnviador(ClienteProxy &clienteProxy, std::atomic<bool> &continuar)
        : cliente(clienteProxy), continuar(continuar){

}

void HiloEnviador::run() {
    try{
        while(continuar){
            cliente.enviarEvento();
        }
    }catch (SocketPeerException &e){
        continuar = false;
    }
}

void HiloEnviador::desconectar(){
    continuar = false;
}

bool HiloEnviador::estaMuerto() {
    return !continuar;
}
