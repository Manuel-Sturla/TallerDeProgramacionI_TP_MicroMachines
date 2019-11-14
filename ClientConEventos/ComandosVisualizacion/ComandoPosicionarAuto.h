//
// Created by diego on 14/11/19.
//

#ifndef CLIENT_COMANDOPOSICIONARAUTO_H
#define CLIENT_COMANDOPOSICIONARAUTO_H


#include "ComandoVisualizacion.h"

class ComandoPosicionarAuto : public ComandoVisualizacion {
public:
    ComandoPosicionarAuto(std::map<std::string, Desplazable*>& desplazables, Renderizador& renderizador);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOPOSICIONARAUTO_H
