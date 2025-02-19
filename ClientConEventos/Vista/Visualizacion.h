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
#include "../Jugador/JugadorReal.h"
#include "../GrabadorVideo/GrabadorVideo.h"

class Visualizacion {
private:
    ServidorProxy& servidor;
    Renderizador renderizador;
    HiloReceptor* receptor;
    HiloLector* lector;
    GrabadorVideo grabador;
    bool keepTalking;
    bool enJuego;
    std::mutex m;
    int fpsRenderizacion;

public:
    explicit Visualizacion(ServidorProxy &servidor, std::shared_ptr<Jugador> &jugador, int anchoPantalla,
                           int alturaPantalla, int fpsRenderizacion, int aumentoCamara);

    void esperarInicioPartida();

    void ejecutarPartida();

    ~Visualizacion();
};


#endif //OPENGLTEST_HILOVISUALIZACION_H
