//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_HILOVISUALIZACION_H
#define OPENGLTEST_HILOVISUALIZACION_H


#include "../Sdl/Renderizador.h"
#include "../Sockets/ServidorProxy.h"
#include "../Hilo.h"
#include "Camara.h"
#include "HiloReceptor.h"
#include "../Juego/Pista.h"

class HiloVisualizacion : public Hilo {
private:
    ServidorProxy& servidor;
    Renderizador renderizador;
    Pista pista;
    Camara camara;
    HiloReceptor* receptor;
    bool& keepTalking;

public:
    explicit HiloVisualizacion(ServidorProxy& servidor, bool& keepTalking);

    void run() override;

    ~HiloVisualizacion() override;
};


#endif //OPENGLTEST_HILOVISUALIZACION_H
