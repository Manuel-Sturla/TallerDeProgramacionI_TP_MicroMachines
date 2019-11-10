//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_ENJUEGO_H
#define SERVIDOR_ENJUEGO_H


#include <map>
#include "EstadoCliente.h"
#include "../Comandos/RecibirAccion.h"
#include "../../Partida/Partida.h"
#include "../../Partida/HashProtegido.h"

class EnJuego: public EstadoCliente {
    RecibirAccion recibirAccion;
    std::map<std::string, std::shared_ptr<Comando>> comandos;

public:
    EnJuego(HashProtegido &partidas);

    void ejecutar(ClienteProxy &cliente) override;
};


#endif //SERVIDOR_ENJUEGO_H
