#include "Servidor.h"
#include "Partida/Partida.h"
#include "Comunicacion/ClienteProxy.h"
#include "Comunicacion/Sockets/SocketPeerException.h"
#include <map>
#include <string>


Servidor::Servidor(const std::string& servicio): socketPasivo(servicio), continuar(true) {
}

Servidor::~Servidor() {
}

void Servidor::run() {

    //Acepto cliente y se une/crea partida
    //partidas.emplace(std::make_pair("prueba",Partida{}));
    //Partida partida = partidas["prueba"];
    Partida partida;
    partida.crearPista(configuracion.darPlanoDePista("Prueba 1"));
    partida.actualizar();
    SocketAmigo socketAmigo = std::move(socketPasivo.aceptarCliente());
    PlanoDeCarro *planoDeCarro = configuracion.darPlanoDeCarro("ManuMovil");
    Carro* unCarro = partida.agregarCliente(planoDeCarro);
    ClienteProxy clienteProxy(std::move(socketAmigo), *this, partida, unCarro);
    clienteProxy.ejecutarComando();
    clienteProxy.start();
    //
    //Esto de aca abajo va ir al hilo de la partida

    while (continuar){
        try{
            clienteProxy.ejecutarAccion();
            partida.simular();
            partida.actualizar();
            clienteProxy.enviarPosiciones();

        }catch (SocketPeerException &e){
            continuar = false;
        }
    }
    clienteProxy.join();
}

std::map<std::string, Partida>& Servidor::obtenerPartidas() {
    return partidas;
}
