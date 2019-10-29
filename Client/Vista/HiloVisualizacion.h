//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_HILOVISUALIZACION_H
#define OPENGLTEST_HILOVISUALIZACION_H


#include "../Sdl/Renderizador.h"
#include "../Servidor.h"
#include "../Hilo.h"
#include "Camara.h"

class HiloVisualizacion : public Hilo {
private:
    Camara camara;
    Renderizador renderizador;
    Servidor& servidor;

public:
    explicit HiloVisualizacion(Servidor& servidor);

    void run() override;
};


#endif //OPENGLTEST_HILOVISUALIZACION_H
