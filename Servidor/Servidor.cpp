#include "Servidor.h"
#include "Partida/Partida.h"
#include "Comunicacion/ClienteProxy.h"
#include "Comunicacion/Sockets/SocketPeerException.h"
#include <map>
#include <chrono>
#include <string>


Servidor::Servidor(const std::string& servicio): socketPasivo(servicio), continuar(true) {
}

Servidor::~Servidor() {
}

void Servidor::run() {

    //Acepto cliente y se une/crea partida
    partidas.emplace(std::piecewise_construct, std::make_tuple("prueba"), std::make_tuple());
    //Creo que usa el constructor por copia entonces todo  muere. Vale tener punteros para evitar los
    //constructores?
    //partidas.emplace(std::pair<std::string, Partida>("prueba2", {}));

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
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
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
