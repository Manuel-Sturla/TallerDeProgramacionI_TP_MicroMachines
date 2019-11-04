//
// Created by manfer on 1/11/19.
//

#ifndef PROTOCOLO_ELEGIRPARTIDA_H
#define PROTOCOLO_ELEGIRPARTIDA_H


#include <map>
#include "../Protocolo.h"
#include "Comando.h"
#include "../../Servidor.h"

class ElegirPartida: public Comando {
    Protocolo& protocolo;
    Servidor& servidor;
public:
    explicit ElegirPartida(Protocolo &protocolo, Servidor &servidor);

    void ejecutar() override;

};


#endif //PROTOCOLO_ELEGIRPARTIDA_H
