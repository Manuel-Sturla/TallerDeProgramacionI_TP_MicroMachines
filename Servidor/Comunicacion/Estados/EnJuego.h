#ifndef SERVIDOR_ENJUEGO_H
#define SERVIDOR_ENJUEGO_H


#include <map>
#include "EstadoCliente.h"
#include "../Eventos/EventosEjecutables/RecibirAccion.h"
#include "../../Partida/Partida.h"
#include "../../Partida/HashProtegido.h"

class EnJuego: public EstadoCliente {
    std::map<std::string, std::shared_ptr<EventoEjecutable>> comandos;

public:
    EnJuego(HashProtegido &partidas);

    void ejecutar(ClienteProxy &cliente) override;
};


#endif //SERVIDOR_ENJUEGO_H
