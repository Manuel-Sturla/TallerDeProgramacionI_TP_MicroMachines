#ifndef SERVIDOR_HILOENVIADOR_H
#define SERVIDOR_HILOENVIADOR_H

#include <atomic>
#include "../Hilo.h"
#include "ColaBloqueante.h"
#include "ClienteProxy.h"

class HiloEnviador: public Hilo {
    ClienteProxy& cliente;
    std::atomic<bool>& continuar;
public:
    explicit HiloEnviador(ClienteProxy &clienteProxy, std::atomic<bool> &continuar);
    void desconectar();
    bool estaMuerto();
    void run() override;
};


#endif //SERVIDOR_HILOENVIADOR_H
