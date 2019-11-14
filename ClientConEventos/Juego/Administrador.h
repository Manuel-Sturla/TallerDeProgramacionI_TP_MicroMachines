//
// Created by diego on 9/11/19.
//

#ifndef CLIENT_ADMINISTRADOR_H
#define CLIENT_ADMINISTRADOR_H


#include <map>
#include "Desplazable.h"
#include "Pista.h"
#include "../ComandosVisualizacion/ComandoVisualizacion.h"

class Administrador {
private:
    std::mutex& m;
    std::map<std::string, ComandoVisualizacion*> comandos;
    std::map<std::string, Desplazable*> desplazables;
    Renderizador& renderizador;
    Pista pista;
    Posicion posTexto;
    size_t idTexto;
    bool& keepTalking;

public:
    explicit Administrador(Renderizador& renderizador, std::mutex& m, bool& keepTalking);

    void ejecutarEventos(std::vector<std::string>& eventos);

    void actualizarJugadores(std::vector<std::string> &evento);

    void crearPista(std::vector<std::string> &planos);

    Desplazable * crearMiAuto(std::vector<std::string> &evento);

    virtual ~Administrador();
};


#endif //CLIENT_ADMINISTRADOR_H
