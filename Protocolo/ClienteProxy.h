//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_CLIENTEPROXY_H
#define PROTOCOLO_CLIENTEPROXY_H


#include "Protocolo.h"
class ClienteProxy {
    Protocolo protocolo;
public:
    ClienteProxy(SocketAmigo socketCliente);
    std::string obtenerComando();
    std::vector<std::string> obtenerPartida();
};


#endif //PROTOCOLO_CLIENTEPROXY_H
