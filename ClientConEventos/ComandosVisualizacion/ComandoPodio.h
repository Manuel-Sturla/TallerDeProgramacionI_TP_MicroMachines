//
// Created by diego on 17/11/19.
//

#ifndef CLIENT_COMANDOPODIO_H
#define CLIENT_COMANDOPODIO_H


#include "ComandoVisualizacion.h"

class ComandoPodio : public ComandoVisualizacion {
private:
    Posicion posPodio;
    bool& keepTalking;

public:
    ComandoPodio(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador, bool &keepTalking);

    void ejecutar(std::vector<std::string> &eventos) override;

    ~ComandoPodio() override = default;
};


#endif //CLIENT_COMANDOPODIO_H
