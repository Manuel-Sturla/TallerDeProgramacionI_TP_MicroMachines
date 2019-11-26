//
// Created by diego on 19/11/19.
//

#ifndef CLIENT_COMANDOPODIO_H
#define CLIENT_COMANDOPODIO_H


#include "ComandoVisualizacion.h"

class ComandoPodio : public ComandoVisualizacion {
private:
    std::string idMiAuto;
    std::vector<std::string> idPodio;
    std::vector<Posicion> posPodio;
    std::map<std::string, Posicion> posJugadores;
    void ponerEnPosicion(Posicion& puesto, Posicion& posJugador);
    void agregarJugador(Posicion &posicion, std::string &idJugador);

public:
    ComandoPodio(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador,
                 std::string idMiAuto);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOPODIO_H
