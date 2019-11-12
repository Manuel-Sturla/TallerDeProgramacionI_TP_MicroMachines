#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include <vector>
#include "Box2D/Box2D.h"
#include "Pista.h"
#include "../Planos/PlanoDePista.h"
#include "../Planos/PlanoDeCarro.h"
#include "../Hilo.h"
#include "../Comunicacion/ClienteProxy.h"
#include "../Comunicacion/Estados/EstadoPartida.h"

class Partida: public Hilo {
private:
    Pista pista;
    std::vector<ClienteProxy*> clientes;
    std::unique_ptr<EstadoPartida> estado;
    std::vector<std::string> suelos;

public:

    Partida(int cantJugadores, PlanoDePista *pista);

    void run() override;

    Carro * agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy* cliente);

    bool estaMuerto();

    void cerrar();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();

    void enviarMensajesInicio();
};

#endif
