
#ifndef SERVIDOR_ENCARRERA_H
#define SERVIDOR_ENCARRERA_H


#include "EstadoPartida.h"
#include "../../Partida/Pista.h"
#include "../ClienteProxy.h"
#include "../../Partida/Podio.h"
#include "../../Partida/HashProtegidoClientes.h"

class EnCarrera {
private:
    Pista& pista;
    Podio podio;
    std::vector<std::string> extras;
    std::vector<std::shared_ptr<EventoParseable>> eventos;
    HashProtegidoClientes& clientes;
    void actualizarEventos();
    void enviarPosiciones();
public:
    EnCarrera(Pista &pista, HashProtegidoClientes &clientes, int cantVueltas);
    void ejecutar();
    void inicializar();
};


#endif //SERVIDOR_ENCARRERA_H
