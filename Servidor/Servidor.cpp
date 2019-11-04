#include "Servidor.h"
#include "Partida/Partida.h"
#include "Comunicacion/ClienteProxy.h"
#include "Comunicacion/Sockets/SocketPeerException.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>


Servidor::Servidor(const std::string& servicio): socketPasivo(servicio), continuar(true) {
      levantarPistas();
}

void Servidor::levantarPistas() {
    std::ifstream pistas("Pistas.txt", std::ifstream::in);
    std::string linea;
    while (!pistas.eof()) {
        getline(pistas, linea);
        if (linea == "Nueva Pista") {
        std::string nombreDePista;
        getline(pistas, nombreDePista);
        planosDePistas.emplace(nombreDePista, new PlanoDePista());
        getline(pistas, linea);
        while (linea != "Fin Pista") {
            planosDePistas[nombreDePista] -> agregarSuelo(linea);
            getline(pistas, linea);
        }
        }
    }
}

Servidor::~Servidor() {
    std::unordered_map<std::string, PlanoDePista*>::iterator it;
    for (it = planosDePistas.begin(); it != planosDePistas.end(); it++) {
        delete it -> second;
    }
}

void Servidor::run() {

    //Acepto cliente y se une/crea partida
    //partidas.emplace(std::make_pair("prueba",Partida{}));
    //Partida partida = partidas["prueba"];
    Partida partida;
    partida.crearPista(planosDePistas["Prueba 1"]);
    partida.actualizar();
    SocketAmigo socketAmigo = std::move(socketPasivo.aceptarCliente());
    ClienteProxy clienteProxy(std::move(socketAmigo), *this, partida);
    clienteProxy.ejecutarComando();
    clienteProxy.start();
    //
    //Esto de aca abajo va ir al hilo de la partida

    while (continuar){
        try{
            clienteProxy.ejecutarAccion(partida.getCarro());
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
