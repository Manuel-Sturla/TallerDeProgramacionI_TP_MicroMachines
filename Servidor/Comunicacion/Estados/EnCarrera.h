
#ifndef SERVIDOR_ENCARRERA_H
#define SERVIDOR_ENCARRERA_H


#include "EstadoPartida.h"
#include "../../Partida/Pista.h"
#include "../ClienteProxy.h"
#include "../../Partida/Podio.h"

class EnCarrera: public EstadoPartida {
private:
    Pista& pista;
    Podio podio;
    std::vector<std::string> extras;
    std::vector<std::shared_ptr<EventoParseable>> eventos;
    std::vector<ClienteProxy*>& clientes;
    void actualizarEventos();
public:
    EnCarrera(Pista& pista, std::vector<ClienteProxy*>& clientes);
    void ejecutar() override;
    bool enJuego() override;
    void enviarPosiciones();
    void cerrar() override;
};


#endif //SERVIDOR_ENCARRERA_H
