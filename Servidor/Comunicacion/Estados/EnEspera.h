#ifndef SERVIDOR_ENESPERA_H
#define SERVIDOR_ENESPERA_H


#include <cstddef>
#include <mutex>
#include <condition_variable>
#include "EstadoPartida.h"
#include "../ClienteProxy.h"
#include "../../Partida/HashProtegidoClientes.h"
#include "../../Partida/Pista.h"
#include "../../Planos/PlanoDeCarro.h"

class EnEspera {
    std::mutex mutex;
    std::condition_variable estaLLena;
    size_t cantMaximaJugadores;
    size_t cantActualJugadores;
    HashProtegidoClientes & clientes;
    size_t contadorId = 0;

    void enviarCantidadDeJugadores();
public:

    explicit EnEspera(size_t cantMaxima, HashProtegidoClientes &clientes);

    void sumarJugador(ClienteProxy &cliente, Pista &pista,
                      PlanoDeCarro *planoCarro);

    bool enJuego();

};


#endif //SERVIDOR_ENESPERA_H
