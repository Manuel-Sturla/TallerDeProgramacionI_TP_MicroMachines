//
// Created by manfer on 7/11/19.
//

#ifndef SERVIDOR_ENESPERA_H
#define SERVIDOR_ENESPERA_H


#include <cstddef>
#include <mutex>
#include <condition_variable>
#include "EstadoPartida.h"
#include "../ClienteProxy.h"
#include "../../Partida/HashProtegidoClientes.h"

class EnEspera: public EstadoPartida {
    std::mutex mutex;
    std::condition_variable estaLLena;
    size_t cantMaximaJugadores;
    size_t cantActualJugadores;
    HashProtegidoClientes & clientes;
    size_t contadorId = 0;

    void enviarCantidadDeJugadores();
public:

    explicit EnEspera(size_t cantMaxima, HashProtegidoClientes &clientes);

    void sumarJugador(ClienteProxy &cliente);

    bool enJuego() override;

    void ejecutar() override;

    void cerrar();
};


#endif //SERVIDOR_ENESPERA_H
