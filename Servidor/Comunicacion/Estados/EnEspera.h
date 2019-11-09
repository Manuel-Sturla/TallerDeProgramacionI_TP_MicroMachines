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

class EnEspera: public EstadoPartida {
    std::mutex mutex;
    std::condition_variable estaLLena;
    size_t cantMaximaJugadores;
    size_t cantActualJugadores;
    std::vector<ClienteProxy*> & clientes;

    void enviarCantidadDeJugadores();
    void cerrarCliente(size_t posicion);
public:

    explicit EnEspera(size_t cantMaxima, std::vector<ClienteProxy*>& clientes);

    void sumarJugador();

    bool enJuego() override;

    void ejecutar() override;

};


#endif //SERVIDOR_ENESPERA_H
