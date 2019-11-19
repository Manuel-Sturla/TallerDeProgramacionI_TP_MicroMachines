//
// Created by diego on 18/11/19.
//

#ifndef CLIENT_COMANDOACTUALIZARVIDA_H
#define CLIENT_COMANDOACTUALIZARVIDA_H


#include "ComandoVisualizacion.h"

class ComandoActualizarVida : public ComandoVisualizacion {
private:
    std::string idVida;
    std::string idMiAuto;
    Posicion posVida;

public:
    ComandoActualizarVida(std::map<std::string, Desplazable *> &desplazables,
                          Renderizador &renderizador, std::string& idMiAuto);

    void ejecutar(std::vector<std::string> &eventos) override;
};


#endif //CLIENT_COMANDOACTUALIZARVIDA_H
