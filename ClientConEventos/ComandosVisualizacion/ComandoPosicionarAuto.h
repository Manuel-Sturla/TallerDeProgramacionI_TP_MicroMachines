//
// Created by diego on 14/11/19.
//

#ifndef CLIENT_COMANDOPOSICIONARAUTO_H
#define CLIENT_COMANDOPOSICIONARAUTO_H


#include "ComandoVisualizacion.h"

class ComandoPosicionarAuto : public ComandoVisualizacion {
private:
	std::string idMiAuto;

public:
    ComandoPosicionarAuto(std::map<std::string, Desplazable*>& desplazables, Renderizador& renderizador, std::string idMiAuto);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOPOSICIONARAUTO_H
