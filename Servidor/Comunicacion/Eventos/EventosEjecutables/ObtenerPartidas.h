#ifndef SERVIDOR_OBTENERPARTIDAS_H
#define SERVIDOR_OBTENERPARTIDAS_H


#include <map>
#include "../../../Partida/Partida.h"
#include "../../../Partida/HashProtegido.h"
#include "EventoEjecutable.h"

class ObtenerPartidas : public EventoEjecutable {
private:
    HashProtegido& partidas;

public:
    explicit ObtenerPartidas(HashProtegido &partidas);

    void ejecutar(ClienteProxy &cliente, std::vector<std::string> argumentos) override;

};


#endif //SERVIDOR_OBTENERPARTIDAS_H
