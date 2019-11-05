#include "Servidor.h"
#include "Partida/Partida.h"
#include "Comunicacion/ClienteProxy.h"
#include "Comunicacion/Sockets/SocketPeerException.h"
#include "Comunicacion/Sockets/SocketPassiveException.h"
#include <map>
#include <string>


Servidor::Servidor(const std::string& servicio): socketPasivo(servicio), continuar(true) {
}

Servidor::~Servidor() {
}

void Servidor::run() {

    //Acepto cliente y se une/crea partida
    //partidas.emplace(std::piecewise_construct, std::forward_as_tuple("prueba"), std::forward_as_tuple());
    //Creo que usa el constructor por copia entonces todo  muere. Vale tener punteros para evitar los
    //constructores?
    //partidas.emplace(std::forward_as_tuple("prueba2", {});
/*
    partidas.emplace("prueba", new Partida());
    std::shared_ptr<Partida> partida = partidas["prueba"];
    partida->crearPista(configuracion.darPlanoDePista("Prueba 1"));
    partida->actualizar();
    SocketAmigo socketAmigo = std::move(socketPasivo.aceptarCliente());
    PlanoDeCarro *planoDeCarro = configuracion.darPlanoDeCarro("ManuMovil");
    Carro* unCarro = partida->agregarCliente(planoDeCarro);
    ClienteProxy clienteProxy(std::move(socketAmigo), *this, unCarro);
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
*/    while (continuar){
        try{
            SocketAmigo socketCliente = socketPasivo.aceptarCliente();
            clientes.emplace_back(new ClienteProxy(socketCliente));
            clientes.back()->start();
            cerrar_clientes_desconectados();
            cerrar_partidas_terminadas();
        }catch (SocketPassiveException &e){
            break;
        }
        //Mato a los clientes
        std::for_each(clientes.begin(), clientes.end(), \
        [](std::shared_ptr<ClienteProxy>& ptr){
            ptr->desconectar();
            ptr->join();
        });
        //Mato a las partidas
        std::for_each(partidas.begin(), partidas.end(), \
        [](std::shared_ptr<Partida>& ptr){
            //ptr->desconectar();
            //ptr->join();
        });
    }
}

std::map<std::string, std::shared_ptr<Partida>> & Servidor::obtenerPartidas() {
    return partidas;
}

void Servidor::cerrar_clientes_desconectados() {
    size_t i = 0;
    while(i < clientes.size()) {
        if (clientes[i]->estaMuerto()) {
            clientes[i]->join();
            clientes.erase(clientes.begin() + i);
        } else {
            i++;
        }
    }

}

void Servidor::cerrar_partidas_terminadas() {
    std::vector <std::string> muertas;
    for (auto it = partidas.begin(); it != partidas.end(); it ++){
        if (it->second->estaMuerto()){
            muertas.emplace_back(it->first);
        }
    };
    for (std::string& clave : muertas){
        partidas[clave]->join();
        partidas.erase(clave);
    }
}
