#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include <vector>
#include "Box2D/Box2D.h"
#include "Pista.h"
#include "../Planos/PlanoDePista.h"
#include "../Planos/PlanoDeCarro.h"
#include "../Hilo.h"
#include "../Comunicacion/ClienteProxy.h"

class Partida: public Hilo {
private:
    Pista pista;
    int cantidadMaximaDeJugadores;
    std::vector<ClienteProxy*> clientes;
    std::atomic<bool> continuar;
    std::vector<std::string> extras;
    std::vector<std::string> autos;
    std::vector<std::string> suelos;

public:
    Partida(int cantJugadores, PlanoDePista *pista);

    void run() override;

    void simular();

    std::vector<std::string>& obtenerExtras();

    std::vector<std::string>& obtenerAutos();

    std::vector<std::string>& obtenerMapa();

    Carro * agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy* cliente);

    void actualizar();

    bool estaMuerto();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();

    void enviarPosicion(ClienteProxy &proxy);
};

#endif
