//
// Created by diego on 17/11/19.
//

#ifndef CLIENT_COMANDOGANADOR_H
#define CLIENT_COMANDOGANADOR_H


#include "ComandoVisualizacion.h"

class ComandoGanador : public ComandoVisualizacion {
private:
    Posicion posPodio;
    bool& keepTalking;
    std::string idGanador;

public:
    ComandoGanador(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador, bool &keepTalking);

    void ejecutar(std::vector<std::string> &eventos) override;

    ~ComandoGanador() override = default;
};


#endif //CLIENT_COMANDOGANADOR_H
