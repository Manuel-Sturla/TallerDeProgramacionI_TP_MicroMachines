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
    int cantidadMaximaDeJugadores;
    std::vector<ClienteProxy*> clientes;
    std::unique_ptr<EstadoPartida> estado;
    std::atomic<bool> continuar;
    std::vector<std::string> suelos;

    void enviarMapa();
public:

    Partida(int cantJugadores, PlanoDePista *pista);

    void run() override;

    std::vector<std::string>& obtenerMapa();

    Carro * agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy* cliente);

    bool estaMuerto();

    void cerrar();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();

    void enviarComenzoLaPartida();

    void enviarAutosPropios();

    void enviarMensajesInicio();
};

#endif
