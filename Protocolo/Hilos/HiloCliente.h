//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_HILOCLIENTE_H
#define PROTOCOLO_HILOCLIENTE_H


#include "Hilo.h"
#include "../ServidorProxy.h"

class HiloCliente: public Hilo {
    ServidorProxy servidorProxy;
public:
    HiloCliente(const std::string& host, const std::string& servicio);

    void run() override;
};


#endif //PROTOCOLO_HILOCLIENTE_H
