//
// Created by diego on 9/11/19.
//

#ifndef CLIENT_ADMINISTRADOR_H
#define CLIENT_ADMINISTRADOR_H


#include <map>
#include "Desplazable.h"
#include "Pista.h"

class Administrador {
private:
    std::mutex& m;
    Renderizador& renderizador;
    std::map<std::string, Desplazable*> desplazables;
    Pista pista;
    Posicion posTexto;
    size_t idTexto;

    void ejecutarMorir(std::vector<std::string> &eventos);
    void ejecutarPosicionarExtra(std::vector<std::string> &eventos);
    void ejecutarModificar(std::vector<std::string> &eventos);
    void ejecutarPosicionarAuto(std::vector<std::string> &vector);

public:
    explicit Administrador(Renderizador& renderizador, std::mutex& m);

    void ejecutarEventos(std::vector<std::string>& eventos);

    void actualizarJugadores(std::vector<std::string> &evento);

    void crearPista(std::vector<std::string> &planos);

    void crearMiAuto(std::vector<std::string> &evento);
};


#endif //CLIENT_ADMINISTRADOR_H
