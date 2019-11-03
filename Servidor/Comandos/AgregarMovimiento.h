//
// Created by manfer on 2/11/19.
//

#ifndef PROTOCOLO_AGREGARMOVIMIENTO_H
#define PROTOCOLO_AGREGARMOVIMIENTO_H


#include <queue>
#include <string>
#include "Comando.h"
#include "../Protocolo.h"

class AgregarMovimiento: public Comando {
    std::queue<std::string> movimientos;
    Protocolo& protocolo;
public:
    explicit AgregarMovimiento(Protocolo& protocolo);

    void ejecutar() override;
};


#endif //PROTOCOLO_AGREGARMOVIMIENTO_H
