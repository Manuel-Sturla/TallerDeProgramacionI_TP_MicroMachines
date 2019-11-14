//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_HILOLECTOR_H
#define OPENGLTEST_HILOLECTOR_H


#include "../Hilo.h"
#include "LectorTeclado.h"
#include "../ComandosTeclado/AdministradorComandosTeclado.h"
#include "../Jugador/JugadorReal.h"

class HiloLector : public Hilo {
private:
    AdministradorComandosTeclado comandos;
    bool& keepTalking;
    std::shared_ptr<Jugador> jugador;

public:
    explicit HiloLector(ServidorProxy &servidor, bool &keepTalking, std::shared_ptr<Jugador> &jugador);

    void run() override;
};


#endif //OPENGLTEST_HILOLECTOR_H
