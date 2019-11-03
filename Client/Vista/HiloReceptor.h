//
// Created by diego on 2/11/19.
//

#ifndef OPENGLTEST_HILORECEPTOR_H
#define OPENGLTEST_HILORECEPTOR_H


#include "../Hilo.h"
#include "../Sockets/ServidorProxy.h"
#include "../Juego/Auto.h"

class HiloReceptor : public Hilo {
private:
    ServidorProxy& servidor;
    bool& keepTalking;
    Auto miAuto;

public:
    explicit HiloReceptor(Renderizador& renderizador, ServidorProxy& servidor, Camara& camara, bool& keepTalking);

    void run() override;
};


#endif //OPENGLTEST_HILORECEPTOR_H
