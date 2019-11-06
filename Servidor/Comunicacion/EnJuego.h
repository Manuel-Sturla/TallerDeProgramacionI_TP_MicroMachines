//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_ENJUEGO_H
#define SERVIDOR_ENJUEGO_H


#include <map>
#include "Estado.h"
#include "Comandos/RecibirAccion.h"
#include "../Partida/Partida.h"

class EnJuego: public Estado {
    RecibirAccion recibirAccion;
    std::map<std::string, std::shared_ptr<Comando>> comandos;

public:
    EnJuego(std::map<std::string, std::shared_ptr<Partida>>& partidas);

    void ejecutar(ClienteProxy &cliente) override;
};


#endif //SERVIDOR_ENJUEGO_H
