//
// Created by diego on 7/11/19.
//

#ifndef SERVIDOR_OBTENERPARTIDAS_H
#define SERVIDOR_OBTENERPARTIDAS_H


#include <map>
#include "Comando.h"
#include "../../Partida/Partida.h"

class ObtenerPartidas : public Comando {
private:
    std::map<std::string, std::shared_ptr<Partida>>& partidas;

public:
    explicit ObtenerPartidas(std::map<std::string, std::shared_ptr<Partida>>& partidas);

    void ejecutar(ClienteProxy &cliente) override;

};


#endif //SERVIDOR_OBTENERPARTIDAS_H
