//
// Created by diego on 14/11/19.
//

#ifndef CLIENT_COMANDOVISUALIZACION_H
#define CLIENT_COMANDOVISUALIZACION_H


#include <map>
#include "../Juego/Desplazable.h"

class ComandoVisualizacion {
protected:
    std::map<std::string, Desplazable*>& desplazables;
    Renderizador& renderizador;

public:
    ComandoVisualizacion(std::map<std::string, Desplazable*>& desplazables, Renderizador& renderizador)\
    : desplazables(desplazables), renderizador(renderizador){}

    virtual void ejecutar(std::vector<std::string> &eventos) = 0;

    virtual ~ComandoVisualizacion() = default;
};


#endif //CLIENT_COMANDOVISUALIZACION_H
