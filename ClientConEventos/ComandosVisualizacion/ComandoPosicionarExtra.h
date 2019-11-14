//
// Created by diego on 14/11/19.
//

#ifndef CLIENT_COMANDOPOSICIONAREXTRA_H
#define CLIENT_COMANDOPOSICIONAREXTRA_H


#include "ComandoVisualizacion.h"

class ComandoPosicionarExtra : public ComandoVisualizacion {
public:
    explicit ComandoPosicionarExtra(std::map<std::string, Desplazable*>& desplazables, Renderizador& renderizador);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOPOSICIONAREXTRA_H
