//
// Created by diego on 14/11/19.
//

#ifndef CLIENT_COMANDOMORIR_H
#define CLIENT_COMANDOMORIR_H


#include "ComandoVisualizacion.h"

class ComandoMorir : public ComandoVisualizacion {
public:
    ComandoMorir(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOMORIR_H
