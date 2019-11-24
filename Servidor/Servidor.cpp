#include "Servidor.h"
#include "Comunicacion/Sockets/SocketPassiveException.h"
#include <chrono>
#include <string>
#include <iostream>


Servidor::Servidor(const std::string& servicio):
socketPasivo(servicio),
continuar(true),
enJuego(partidas),
enMenu(partidas, configuracion){
    //Partida hardcodeada para probar
    partidas.ubicar("prueba", new Partida(1, configuracion.darPlanoDePista("Dona")));
    partidas.obtener("prueba") -> start();
}

Servidor::~Servidor() {
}

void Servidor::run() {
   while (continuar){
        try{
            SocketAmigo socketCliente = socketPasivo.aceptarCliente();
            std::cout << "aceptado!" << std::endl;
            clientes.emplace_back(new HiloCliente(socketCliente, enMenu, enJuego, partidas));
            clientes.back()->start();
            cerrar_clientes_desconectados();
            cerrar_partidas_terminadas();
        }catch (SocketPassiveException &e){
            break;
        }
    }
    //Mato a los clientes
    for (auto& cliente : clientes){
        cliente->desconectar();
        cliente->join();
    }
    //Mato a las clientes
    for (auto& partida : partidas.obtenerClaves()) {
        partidas.obtener(partida)->cerrar();
        partidas.obtener(partida)->join();
    }
}


HashProtegido & Servidor::obtenerPartidas() {
    return partidas;
}

void Servidor::cerrar_clientes_desconectados() {
    size_t i = 0;
    while(i < clientes.size()) {
        if (clientes[i]->estaMuerto()) {
            clientes[i]->desconectar();
            clientes[i]->join();
            clientes.erase(clientes.begin() + i);
        } else {
            i++;
        }
    }

}

void Servidor::cerrar_partidas_terminadas() {
    for (auto& partida : partidas.obtenerClaves()){
        if (partidas.obtener(partida)->estaMuerto()){
            partidas.obtener(partida)->join();
            partidas.eliminar(partida);
        }
    }
}

void Servidor::apagar() {
    continuar = false;
    socketPasivo.cerrar();
}
