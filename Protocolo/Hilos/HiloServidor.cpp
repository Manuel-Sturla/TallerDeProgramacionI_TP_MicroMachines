//
// Created by manfer on 31/10/19.
//

#include <iostream>
#include "HiloServidor.h"
#include "../Utilidades.h"

#define SEPARADOR ';'

HiloServidor::HiloServidor(const std::string &servicio):
socket(servicio){
}

void HiloServidor::run() {
    Partida partida;
    ClienteProxy clienteProxy2(socket.aceptarCliente(), partida);
    clienteProxy = &clienteProxy2;
    std::cout << "Inicio Prueba de obtener posiciones" << std::endl;
    clienteProxy->ejecutarComando();
    std::cout << "Inicio Prueba de obtener mapa" << std::endl;
    clienteProxy->ejecutarComando();
    //std::cout << "Partida nueva obtenida: " << unir(clienteProxy->obtenerPartida(), SEPARADOR) << std::endl;
    //std::cout << "PArtida elegida:  " <<  unir(clienteProxy->obtenerPartida(), SEPARADOR) << std::endl;
}
