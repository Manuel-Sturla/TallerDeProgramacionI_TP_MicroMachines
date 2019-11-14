//
// Created by diego on 14/11/19.
//

#ifndef CLIENT_COMANDOELIMINAR_H
#define CLIENT_COMANDOELIMINAR_H


#include "ComandoVisualizacion.h"

class ComandoEliminar : public ComandoVisualizacion {
public:
    ComandoEliminar(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOELIMINAR_H
