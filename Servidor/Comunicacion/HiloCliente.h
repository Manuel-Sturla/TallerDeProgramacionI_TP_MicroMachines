//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_HILOCLIENTE_H
#define SERVIDOR_HILOCLIENTE_H


#include "../Hilo.h"
#include "ClienteProxy.h"
#include "EnJuego.h"
#include "EnMenu.h"

class HiloCliente: public Hilo {
    ClienteProxy cliente;
    EnMenu& menu;
    EnJuego& juego;
    Estado* estado;
    std::atomic<bool> conectado;

public:
    HiloCliente(SocketAmigo& cliente, EnMenu& enMenu, EnJuego& enJuego);
    void desconectar();
    bool estaMuerto();
    void run() override;
};


#endif //SERVIDOR_HILOCLIENTE_H
