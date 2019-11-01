//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_HILOSERVIDOR_H
#define PROTOCOLO_HILOSERVIDOR_H


#include <SocketPasivo.h>
#include "Hilo.h"
#include "../ClienteProxy.h"

class HiloServidor: public Hilo {
    SocketPasivo socket;
    ClienteProxy* clienteProxy;
public:
    HiloServidor(const std::string& servicio);

    void run() override;
};


#endif //PROTOCOLO_HILOSERVIDOR_H
