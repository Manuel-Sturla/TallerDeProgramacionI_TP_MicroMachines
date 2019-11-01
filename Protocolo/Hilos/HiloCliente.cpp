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
    servidorProxy.ejecutarComando("Asadf");
    servidorProxy.crearPartida("MANU es el mas capo de todoos", 9);
    servidorProxy.elegirPartida("MANUUSX");
}
