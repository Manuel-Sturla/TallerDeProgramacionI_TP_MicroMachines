//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_HILOCLIENTE_H
#define SERVIDOR_HILOCLIENTE_H


#include "../Hilo.h"
#include "ClienteProxy.h"
#include "Estados/EnJuego.h"
#include "Estados/EnMenu.h"
#include "HiloEnviador.h"

class HiloCliente: public Hilo {
    ClienteProxy cliente;
    EnMenu& menu;
    EnJuego& juego;
    EstadoCliente* estado;
    HashProtegido& partidas;
    std::atomic<bool> conectado;
    HiloEnviador enviador;

public:
    HiloCliente(SocketAmigo &socketCliente, EnMenu &enMenu, EnJuego &enJuego, HashProtegido &partidas);
    void desconectar();
    bool estaMuerto();
    void run() override;
};


#endif //SERVIDOR_HILOCLIENTE_H
