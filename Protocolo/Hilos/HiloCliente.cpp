//
// Created by manfer on 31/10/19.
//

#include <iostream>
#include "HiloCliente.h"

HiloCliente::HiloCliente(const std::string& host, const std::string& servicio):
servidorProxy(host, servicio){
}

void HiloCliente::run() {
    //std::cout << "Envio Comando" << std::endl;
    /*std::vector<std::string> partidas = servidorProxy.obtenerPartidas();
    std::cout << "Partidas obtenidas" << std::endl;
    for (auto& partida : partidas){{
        std::cout << partida << ", ";
    }}
    servidorProxy.crearPartida("MANU es el mas capo de todoos", 9);
    //servidorProxy.elegirPartida("MANUUSX");
*/
    std::vector<std::string> extras;
    std::vector<std::string> autos;
    servidorProxy.obtenerPosiciones(extras, autos);
    std::cout << "EXTRAS: ";
    for (auto& extra : extras){
            std::cout << extra << ", ";
    }
    std::cout << std::endl;
    std::cout << "AUTOS: ";
    for (auto& miAuto : autos){
        std::cout << miAuto << ", ";
    }
    std::cout << std::endl;
    std::cout << "MAPA: ";
    std::vector<std::string> mapa = servidorProxy.obtenerMapa();
    for (auto& pos : mapa){
        std::cout << pos << ", ";
    }
    std::cout << std::endl;
}
