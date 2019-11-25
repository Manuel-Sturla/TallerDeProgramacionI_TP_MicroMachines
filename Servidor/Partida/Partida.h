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
#include "HashProtegidoClientes.h"
#include "../Mods/Mod.h"
#include "../Comunicacion/Estados/EnEspera.h"
#include "../Comunicacion/Estados/EnCarrera.h"

class Partida: public Hilo {
private:
    HashProtegidoClientes clientes;
    Pista pista;
    EnEspera estadoEnEspera;
    EnCarrera estadoEnCarrera;
    std::vector<std::string> suelos;
    std::vector<std::unique_ptr<Mod>>& mods;
    std::mutex mutex;
    std::condition_variable estaLlena;
    std::atomic<bool> enJuego;

public:

    Partida(int cantJugadores, PlanoDePista *planoPista, int cantVueltas, std::vector<std::unique_ptr<Mod>> &modsAUsar);

    void run() override;

    std::vector<std::string>& obtenerMapa();

    void agregarCliente(PlanoDeCarro *planoDeCarro, ClienteProxy &cliente);

    void eliminarCliente(ClienteProxy& cliente);

    bool estaMuerto();

    void cerrar();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();

    void enviarMensajesInicio();

    bool estaEnJuego();

    void llamarMods();
};

#endif
