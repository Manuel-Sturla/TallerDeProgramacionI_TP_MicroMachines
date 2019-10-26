//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_HILOLECTOR_H
#define OPENGLTEST_HILOLECTOR_H


#include "../Hilo.h"
#include "LectorTeclado.h"
#include "../Comandos/AdministradorComandos.h"

class HiloLector : public Hilo {
private:
    AdministradorComandos comandos;

public:
    explicit HiloLector(Servidor& servidor);

    void run() override;
};


#endif //OPENGLTEST_HILOLECTOR_H
