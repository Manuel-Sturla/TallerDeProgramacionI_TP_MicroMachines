//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_HILOLECTOR_H
#define OPENGLTEST_HILOLECTOR_H


#include "../Hilo.h"
#include "../ComandosTeclado/AdministradorComandosTeclado.h"
#include "../Jugador/JugadorReal.h"

class HiloLector : public Hilo {
private:
    AdministradorComandosTeclado comandos;
    bool& keepTalking;
    ServidorProxy& servidor;
    std::shared_ptr<Jugador> jugador;
    int fpsRenderizacion;

public:
    explicit HiloLector(ServidorProxy &servidor, bool &keepTalking, std::shared_ptr<Jugador> &jugador,
                        int fpsRenderizacion, GrabadorVideo &grabador);

    void run() override;
};


#endif //OPENGLTEST_HILOLECTOR_H
