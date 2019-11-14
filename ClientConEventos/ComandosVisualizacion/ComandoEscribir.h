//
// Created by diego on 14/11/19.
//

#ifndef CLIENT_COMANDOESCRIBIR_H
#define CLIENT_COMANDOESCRIBIR_H


#include "ComandoVisualizacion.h"

class ComandoEscribir : public ComandoVisualizacion {
private:
    Posicion posTexto;
    size_t idTexto;

public:
    ComandoEscribir(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOESCRIBIR_H
