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
#include "../Lector/HiloLector.h"

class HiloVisualizacion {
private:
    ServidorProxy& servidor;
    Renderizador renderizador;
    HiloReceptor* receptor;
    HiloLector* lector;
    bool keepTalking;
    bool enJuego;
    std::mutex m;
public:
    explicit HiloVisualizacion(ServidorProxy &servidor);

    void esperarInicioPartida();

    void ejecutarPartida();

    ~HiloVisualizacion();
};


#endif //OPENGLTEST_HILOVISUALIZACION_H
