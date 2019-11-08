
#ifndef SERVIDOR_ENCARRERA_H
#define SERVIDOR_ENCARRERA_H


#include "EstadoPartida.h"
#include "../../Partida/Pista.h"
#include "../ClienteProxy.h"

class EnCarrera: public EstadoPartida {
private:
    Pista& pista;
    std::vector<std::string> extras;
    std::vector<std::string> autos;
    std::vector<ClienteProxy*> clientes;
    void actualizarEventos();
public:
    EnCarrera(Pista& pista, std::vector<ClienteProxy*>& clientes);
    void ejecutar() override;
    bool enJuego() override;
    void enviarPosicion(ClienteProxy &proxy);
};


#endif //SERVIDOR_ENCARRERA_H
