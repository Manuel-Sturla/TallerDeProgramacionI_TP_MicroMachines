//
// Created by manfer on 1/11/19.
//

#ifndef PROTOCOLO_ELEGIRPARTIDA_H
#define PROTOCOLO_ELEGIRPARTIDA_H


#include <map>
#include "../Protocolo.h"
#include "Comando.h"

class ElegirPartida: public Comando {
    Protocolo& protocolo;
    std::map<std::string, std::string>& partidas;
public:
    explicit ElegirPartida(Protocolo &protocolo, std::map<std::string, std::string> &partidas);

    void ejecutar() override;

};


#endif //PROTOCOLO_ELEGIRPARTIDA_H
