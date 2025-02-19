//
// Created by diego on 2/11/19.
//

#ifndef OPENGLTEST_HILORECEPTOR_H
#define OPENGLTEST_HILORECEPTOR_H


#include "../Hilo.h"
#include "../Sockets/ServidorProxy.h"
#include "../Juego/Auto.h"
#include "../Juego/Administrador.h"
#include "../Jugador/JugadorReal.h"

class HiloReceptor : public Hilo {
private:
    ServidorProxy& servidor;
    bool& keepTalking;
    Administrador admin;
    bool& enJuego;
    std::shared_ptr<Jugador> jugador;
    std::mutex& m;
    void esperarInicioPartida();
    void inicializarPartida();
    int fpsRenderizacion;

public:

    explicit HiloReceptor(Renderizador &renderizador, ServidorProxy &servidor, bool &keepTalking, bool &enJuego,
                          std::mutex &m,
                          std::shared_ptr<Jugador> &jugador, int fpsRenderizacion);

    void run() override;
};


#endif //OPENGLTEST_HILORECEPTOR_H
