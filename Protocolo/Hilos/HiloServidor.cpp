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
    ClienteProxy clienteProxy2(socket.aceptarCliente());
    clienteProxy = &clienteProxy2;
    std::cout << "Inicio Prueba de obtener comando" << std::endl;
    std::cout << "Comando obtenido: " << clienteProxy->obtenerComando() << std::endl;
    std::cout << "Partida nueva obtenida: " << unir(clienteProxy->obtenerPartida(), SEPARADOR) << std::endl;
    std::cout << "PArtida elegida:  " <<  unir(clienteProxy->obtenerPartida(), SEPARADOR) << std::endl;
}
