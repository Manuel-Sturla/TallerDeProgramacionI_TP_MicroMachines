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
#include "../Jugador/Jugador.h"

class Visualizacion {
private:
    ServidorProxy& servidor;
    Renderizador renderizador;
    HiloReceptor* receptor;
    HiloLector* lector;
    bool keepTalking;
    bool enJuego;
    std::mutex m;
public:
    explicit Visualizacion(ServidorProxy &servidor, std::shared_ptr<Jugador> &jugador);

    void esperarInicioPartida();

    void ejecutarPartida();

    ~Visualizacion();
};


#endif //OPENGLTEST_HILOVISUALIZACION_H
